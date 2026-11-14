import { createSupervisor } from '@langchain/langgraph-supervisor';
import { createReactAgent } from '@langchain/langgraph/prebuilt';
import {
  providers,
  agentRole,
  agentFramework,
  serviceTypes,
  agentToolTypes,
  externalAgentProviders,
} from '../../../sharedLibrary/constants';
import { getMCPConfig } from '../MCPConfig';
import { ChatOpenAI } from '@langchain/openai';
import SandboxManager from '../SandboxManager';
import { tool } from '@langchain/core/tools';
import OrchestratorService from '../../orchestratorService';
import { ChatGoogleGenerativeAI } from '@langchain/google-genai';
import { ChatBedrockConverse } from '@langchain/aws';
import Config from '../../../../config';
import LHTLogger from '../../../utils/logger';
import { ChatGroq } from '@langchain/groq';
import { z } from 'zod';
import axios from 'axios';
import { GEMINI_DEEP_RESEARCH_MODEL } from '../../../common/constants';
import FlowService from '../../flowService';
import MultiAgentService from '../../multiAgentService';
import Mem0 from '../../mem0Service';
import { InterruptError, ZBrainLangGraphAgent } from './Agent';
import { SessionData } from './SessionData';

import { Command } from '@langchain/langgraph';
import { ActivityStatus } from '../../../common/constants';
import RabbitMqController from '../../../modules/queue';
import AzureFoundryFramework from '../azureFoundry';
import BedrockFramework from '../bedrock';
import Utils from '../../../utils';
import { Scratchpad } from './scratchpad';


export default class AgentFactory {
  constructor({
    provider,
    apiKey,
    model,
    tenantId,
    projectId,
    platformId,
    enableThoughtTracing = false,
    memoryType,
    infer,
    threshold,
    limit,
    customInstruction,
    crewId,
    service = serviceTypes.ZBRAIN,
    dbModels,
  }) {
    this.apiKey = apiKey;
    this.framework = agentFramework.LANGGRAPH;
    this.enableThoughtTracing = enableThoughtTracing;
    switch (provider) {
      case providers.GOOGLE:
        this.service = new ChatGoogleGenerativeAI({
          model: model,
          apiKey: Config.GEMINI_API_KEY,
        });
        break;
      case providers.CLAUDE:
      case providers.META_LLAMA:
        this.service = new ChatBedrockConverse({
          model: model,
          region: Config.BEDROCK_REGION,
          credentials: {
            accessKeyId: Config.BEDROCK_ACCESS_KEY,
            secretAccessKey: Config.BEDROCK_SECRET_KEY,
          },
        });
        break;
      case providers.GROQ:
        this.service = new ChatGroq({
          model: model,
          apiKey: Config.GROQ_API_KEY,
        });
        break;
      case providers.OPEN_ROUTER:
        this.service = new ChatOpenAI({
          apiKey: Config.OPEN_ROUTER_API_KEY,
          configuration: {
            baseURL: 'https://openrouter.ai/api/v1',
          },
          model,
        });
        break;
      case providers.OPENAI:
        this.service = new ChatOpenAI({
          apiKey: apiKey,
          model,
        });
        break;
      default:
        break;
    }
    this.tenantId = tenantId;
    this.projectId = projectId;
    this.platformId = platformId;
    this.orchestratorService = new OrchestratorService();
    this.flowService = new FlowService();
    this.rootAgentName = 'Unnamed Agent';
    this.memoryType = memoryType;
    this.infer = infer;
    this.threshold = threshold;
    this.limit = limit;
    this.customInstruction = customInstruction;

    this.crewId = crewId;
    this.mem0 = new Mem0(
      this.memoryType,
      this.tenantId,
      this.crewId,
      this.infer,
      this.limit,
      this.threshold,
      this.customInstruction
    );
    // this.mem0 = {};
    this.usage = {};

    this.inputActivity = [];

    this.httpInputActivity = {};
    this.serviceApp = service;

    this.agentModelMapping = {};

    this.dbModels = dbModels;
    this.sessionService = new SessionData(this.dbModels);
  }

  _getLlmService(modelDetails) {
    switch (modelDetails.provider) {
      case providers.GOOGLE:
        return new ChatGoogleGenerativeAI({
          model: modelDetails.name,
          apiKey: Config.GEMINI_API_KEY,
          temperature: modelDetails.configurations?.temperature,
          topP: modelDetails.configurations?.topP,
          maxOutputTokens: modelDetails.configurations?.maxTokens,
        });
      case providers.CLAUDE:
      case providers.META_LLAMA:
        return new ChatBedrockConverse({
          model: modelDetails.name,
          region: Config.BEDROCK_REGION,
          credentials: {
            accessKeyId: Config.BEDROCK_ACCESS_KEY,
            secretAccessKey: Config.BEDROCK_SECRET_KEY,
          },
          temperature: modelDetails.configurations?.temperature,
          topP: modelDetails.configurations?.topP,
          maxTokens: modelDetails.configurations?.maxTokens,
        });
      case providers.GROQ:
        return new ChatGroq({
          model: modelDetails.name,
          apiKey: Config.GROQ_API_KEY,
          temperature: modelDetails.configurations?.temperature,
          topP: modelDetails.configurations?.topP,
          maxTokens: modelDetails.configurations?.maxTokens,
          frequencyPenalty: modelDetails.configurations?.frequencyPenalty,
          presencePenalty: modelDetails.configurations?.presentPenalty,
        });
      case providers.OPEN_ROUTER:
        return new ChatOpenAI({
          apiKey: Config.OPEN_ROUTER_API_KEY,
          configuration: {
            baseURL: 'https://openrouter.ai/api/v1',
          },
          model: modelDetails.name,
          temperature: modelDetails.configurations?.temperature,
          topP: modelDetails.configurations?.topP,
          maxCompletionTokens: modelDetails.configurations?.maxTokens,
          frequencyPenalty: modelDetails.configurations?.frequencyPenalty,
          presencePenalty: modelDetails.configurations?.presentPenalty,
        });
      case providers.OPENAI:
        return new ChatOpenAI({
          apiKey: this.apiKey,
          model: modelDetails.name,
          temperature: modelDetails.configurations?.temperature,
          topP: modelDetails.configurations?.topP,
          maxCompletionTokens: modelDetails.configurations?.maxTokens,
          frequencyPenalty: modelDetails.configurations?.frequencyPenalty,
          presencePenalty: modelDetails.configurations?.presentPenalty,
        });
      default:
        return;
    }
  }

  _createAgent(name, prompt, tools = [], service = this.service) {
    return createReactAgent({
      name,
      prompt,
      llm: service,
      tools,
    });
  }

  _createSupervisorAgent(name, prompt, workerAgents = []) {
    const agents = workerAgents.map((workerAgent) => {
      return this._createAgent(
        workerAgent.name,
        workerAgent.instructions,
        workerAgent.tools
      );
    });

    return createSupervisor({
      supervisorName: name,
      prompt,
      llm: this.service,
      agents,
    });
  }

  _createTool(toolObject) {
    switch (toolObject.type) {
      case agentToolTypes.CODE:
        return tool(
          async (input) => {
            const runToolOrchestratorInput =
              this.orchestratorService.prepareCodeToolAPIInput(
                toolObject.name,
                toolObject.script,
                toolObject.dependencies,
                input
              );
            return await this.orchestratorService.runCodeTool(
              runToolOrchestratorInput,
              this.tenantId,
              this.projectId,
              this.platformId
            );
          },
          {
            name: toolObject.name,
            description: toolObject.description,
            schema: SandboxManager.mapInputSchemaToZod(toolObject.inputSchema),
          }
        );
      case agentToolTypes.FLOW:
        return tool(
          async (input) => {
            if (
              input &&
              typeof input === 'object' &&
              input['_flowAgentBodyData_']
            ) {
              input = input['_flowAgentBodyData_'];
            }
            const response = await this.flowService.webHookRunSync(
              toolObject._id,
              input,
              this.tenantId
            );
            return response?.result?.output || response?.result || 'No output';
          },
          {
            name: toolObject.name,
            description: toolObject.description,
            schema: SandboxManager.mapInputSchemaToZod(toolObject.inputSchema),
          }
        );
      case agentToolTypes.DEFAULT:
        switch (toolObject.name) {
          case 'http':
            return this.httpTool(toolObject);
          case 'google_search':
            return this.googleSearchTool(toolObject);
          case 'knowledge_base_search':
            return this.knowledgeBaseSearchTool(toolObject);
          case 'deep_research':
            return this.deepResearchTool(toolObject);
          default:
            break;
        }
        break;
      case agentToolTypes.EXTERNAL_AGENT: {
        return tool(
          async (input) => {
            let agent = null;
            switch (toolObject.data.provider) {
              case externalAgentProviders.AWS_BEDROCK:
                agent = new BedrockFramework({
                  accessKeyId: toolObject.data.credentials.accessKeyId,
                  secretAccessKey: toolObject.data.credentials.secretAccessKey,
                  region: toolObject.data.credentials.region,
                });
                break;
              case externalAgentProviders.AZURE_FOUNDRY:
                agent = new AzureFoundryFramework({
                  endpoint: toolObject.data.credentials.endpoint,
                  tenantId: toolObject.data.credentials.tenantId,
                  clientId: toolObject.data.credentials.clientId,
                  clientSecret: toolObject.data.credentials.clientSecret,
                });
                break;
              default:
                throw new Error(
                  `Unsupported external agent provider: ${toolObject.data.provider}`
                );
            }
            try {
              const response = await agent.invoke(
                toolObject.data.agentId,
                input.inputText
              );
              return response;
            } catch (error) {
              LHTLogger.error(`Error invoking agent: ${error}`);
              throw error;
            }
          },
          {
            name: toolObject.name,
            description: toolObject.description,
            schema: z.object({
              inputText: z
                .string()
                .describe(`Input text for the ${toolObject.name} agent`),
            }),
          }
        );
      }
    }
  }
  async _makeQueryEngineRequest(data) {
    try {
      const { data: response } = await axios.post(
        `${Config.QUERY_ENGINE_MICROSERVICE}/v2/internal/chat/response`,
        data,
        {
          headers: {
            'Content-Type': 'application/json',
            'x-secret-key': Config.INTERNAL_SECRET_KEY,
          },
          timeout: 3300000, // 55 minutes
        }
      );
      return response;
    } catch (error) {
      LHTLogger.error('Error making query engine request:', error);
      throw new Error(`Query engine request failed: ${error.message}`);
    }
  }
  async initializeAgents(agentData) {
    if (agentData.type === agentRole.SUPERVISOR) {
      if (agentData.workerAgents && agentData.workerAgents.length > 0) {
        agentData.workerAgents = await Promise.all(
          agentData.workerAgents.map(async (agent) => {
            let mcps = [];
            if (agentData.tools.mcpList?.length > 0) {
              const McpConfig = getMCPConfig(agent.tools.mcpList);
              mcps = await McpConfig.getTools();
            }
            const tools = agent.tools.toolList.flatMap((toolObj) =>
              this._createTool(toolObj)
            );
            agent.tools = [...mcps, ...tools];
            return agent;
          })
        );
      }
      this.agent = this._createSupervisorAgent(
        agentData.name,
        agentData.instructions,
        agentData.workerAgents
      ).compile({ name: agentData.name });
    } else {
      let mcps = [];
      if (agentData.tools.mcpList?.length > 0) {
        const McpConfig = getMCPConfig(agentData.tools.mcpList);
        mcps = await McpConfig.getTools();
      }
      const tools = agentData.tools.toolList?.flatMap((toolObj) =>
        this._createTool(toolObj)
      );

      this.agent = this._createAgent(agentData.name, agentData.instructions, [
        ...mcps,
        ...tools,
      ]);
    }
  }

  async initializeAgentCrew({
    nodes,
    edges,
    model,
    agentsData,
    input,
    scratchpads = [],
  }) {
    const nodeMap = new Map(nodes.map((node) => [node.id, node]));
    const createdAgents = new Map();

    const childToParents = new Map();
    const parentToChildren = new Map();
    edges.forEach((edge) => {
      if (!childToParents.has(edge.target)) {
        childToParents.set(edge.target, []);
      }
      if (!parentToChildren.has(edge.source)) {
        parentToChildren.set(edge.source, []);
      }
      childToParents.get(edge.target).push(edge.source);
      parentToChildren.get(edge.source).push(edge.target);
    });

    const leafNodes = nodes.filter(
      (node) => !edges.some((edge) => edge.source === node.id)
    );

    const rootNode = nodes.find((node) => node.type === 'root');

    this.rootAgentName = rootNode.data.label || 'Unnamed Agent';

    const scratchpadMap = new Map(
      (scratchpads || []).map((sp) => [sp.id, new Scratchpad(sp.id, sp.name)])
    );

    const processedNodes = new Set();
    const queue = [...leafNodes];

    while (queue.length > 0) {
      const currentNode = queue.shift();
      const nodeId = currentNode.id;

      if (processedNodes.has(nodeId)) continue;

      const agentId = currentNode.data.agentId.toString();
      const agentData = agentsData.get(agentId);

      this.sessionService.agentModelMapping[agentData.name] =
        agentData.modelDetails ?? { name: model, provider: this.provider };
      this.sessionService.agentNames.push(agentData?.name?.toLowerCase());

      if (!agentData) {
        throw new Error(`Agent data missing for agentId ${agentId}`);
      }

      let mcps = [],
        tools = [];

      if (agentData.tools?.mcpList?.length > 0) {
        const McpConfig = getMCPConfig(agentData.tools.mcpList);
        mcps = await McpConfig.getTools();
      }

      if (agentData.tools?.toolList?.length > 0) {
        tools = agentData.tools?.toolList?.flatMap((toolObj) =>
          this._createTool(toolObj)
        );
      }

      if (currentNode.data?.scratchpads?.length > 0) {
        for (const scratchpadId of currentNode.data.scratchpads) {
          const scratchpad = scratchpadMap.get(scratchpadId);
          if (scratchpad) {
            tools.push(...this.scratchpadObjectToTools(scratchpad));
          }
        }
      }

      const childNodeIds = parentToChildren.get(nodeId) || [];
      const childAgents = childNodeIds
        .map((childId) => createdAgents.get(childId))
        .filter(Boolean);

      let service = agentData.modelDetails
        ? this._getLlmService(agentData.modelDetails)
        : this.service;
      if (!service) {
        throw new Error(`Agent model Details missing for agentId ${agentId}`);
      }
      let systemMessage = null;
      if (nodeId === rootNode.id && input) {
        systemMessage = await this.mem0.getAgentMemoriesAsSystemPrompt(
          JSON.stringify(Utils.cleanUpAgentInput(input))
        );
        Object.entries(this.mem0.tokenUsage).forEach(([model, data]) => {
          if (typeof data !== 'object') return;
          this.sessionService.updateTokenUsage(
            model,
            data.prompt || 0,
            data.completion || 0,
            data.type,
            data.total_tokens || 0
          );
        });
      }
      const agent = new ZBrainLangGraphAgent({
        name: agentData.name,
        instructions: `${agentData.instructions}${
          systemMessage ? `\n\n${systemMessage.content}` : ''
        }`,
        description: agentData.description,
        llm: service,
        tools: [...mcps, ...tools],
        subAgents: childAgents,
        traceThoughts: this.enableThoughtTracing,
        agentId: agentId,
        humanFeedbackRequired: agentData.humanFeedbackRequired,
        sessionService: this.sessionService,
      });

      createdAgents.set(nodeId, agent);
      processedNodes.add(nodeId);

      const parentNodes = childToParents.get(nodeId) || [];
      for (const parentId of parentNodes) {
        const allChildrenProcessed = (
          parentToChildren.get(parentId) || []
        ).every((childId) => processedNodes.has(childId));

        if (allChildrenProcessed && !processedNodes.has(parentId)) {
          queue.push(nodeMap.get(parentId));
        }
      }
    }
    this.agent = createdAgents.get(rootNode.id);
  }

  processMessageContent = (data, previousContent) => {
    if (!data.content) {
      return { shouldContinue: true };
    }
    let content = data.content;
    if (Array.isArray(data.content)) {
      content = data.content[0][data.content[0].type];
    }
    if (
      typeof content === 'string' &&
      content.startsWith('Transferring back')
    ) {
      return { shouldStop: true };
    }

    return {
      shouldContinue: true,
      activity: {
        name: data.name,
        input: previousContent,
        output: content || '',
        status: 'SUCCEEDED',
        duration: 0,
        errorMessage: '',
      },
      newContent: content,
    };
  };

  processToolCalls = ({ data, messages, index, previousContent }) => {
    const toolOutput = [];
    let nextIndex = index + 1;
    const activities = [];

    data.tool_calls.forEach((toolCall) => {
      if (toolCall.name.startsWith('transfer_to')) {
        activities.push({
          name: data.name,
          input: previousContent,
          status: 'SUCCEEDED',
          duration: 0,
          errorMessage: '',
        });
      } else {
        activities.push({
          name: data.name,
          input: previousContent,
          output: `Calling ${toolCall.name}`,
          status: 'SUCCEEDED',
          duration: 0,
          errorMessage: '',
        });

        let toolArgs = toolCall.args;

        if (toolCall.id in this.httpInputActivity) {
          toolArgs = this.httpInputActivity[toolCall.id];
        }

        if (messages.messages[nextIndex]?.kwargs?.content) {
          activities.push({
            name: toolCall.name,
            input: toolArgs,
            output: messages.messages[nextIndex]?.kwargs?.content || '',
            status: 'SUCCEEDED',
            duration: 0,
            errorMessage: '',
          });
        } else {
          this.inputActivity.push({
            callID: toolCall.id,
            name: toolCall.name,
            args: toolArgs,
          });
        }

        if (messages.messages[nextIndex]?.kwargs?.content) {
          toolOutput.push(messages.messages[nextIndex]?.kwargs?.content);
        }
        nextIndex++;
      }
    });

    return {
      activities,
      toolOutput,
      nextIndex: nextIndex - 1,
    };
  };

  processMessages = (initialContent, agentMessages, startIndex = 0) => {
    const agentActivity = [];
    let previousContent = initialContent;
    let index = startIndex;
    const agentOutputs = [];

    try {
      while (index < agentMessages.messages.length) {
        const message = agentMessages.messages[index];
        const data = message.kwargs || {};
        let stop = false;

        switch (message.id[2]) {
          case 'AIMessage': {
            // Process AI message
            let toolOutput = [];

            if (data.content) {
              const result = this.processMessageContent(data, previousContent);

              if (result.shouldStop) {
                if (agentOutputs.length > 0 && agentActivity.length > 0) {
                  agentActivity[agentActivity.length - 1].input =
                    agentOutputs.join(', ');
                }
                stop = true;
                break;
              }

              if (result.activity) {
                agentActivity.push(result.activity);
                previousContent = result.newContent;
              }
            } else if (data.tool_calls?.length > 0) {
              // Process tool calls
              const result = this.processToolCalls({
                data,
                messages: agentMessages,
                index,
                previousContent,
              });

              agentActivity.push(...result.activities);
              toolOutput = result.toolOutput;
              index = result.nextIndex;
            }

            if (toolOutput.length > 0) {
              previousContent = toolOutput.join(', ');
            }
            break;
          }

          case 'ToolMessage':
            if (data.name?.startsWith('transfer_to')) {
              const toolName = data.content.split(
                'Successfully transferred to '
              )[1];

              if (agentActivity.length > 0) {
                const last = agentActivity[agentActivity.length - 1];
                last.output =
                  (last.output ? last.output + '\n' : '') +
                  `Calling ${toolName}`;
              }

              const [activity, newIndex, agentOutput] = this.processMessages(
                previousContent,
                agentMessages,
                index + 1
              );
              if (activity.length > 0) {
                agentActivity.push(...activity);

                if (agentOutput) {
                  agentOutputs.push(agentOutput);
                }
              }
              index = newIndex;
            } else if (data.tool_call_id) {
              if (this.inputActivity && data?.tool_call_id) {
                const index = this.inputActivity.findIndex(
                  (_activity) => _activity.callID === data.tool_call_id
                );
                if (index !== -1) {
                  previousContent = this.inputActivity[index].args;
                  this.inputActivity.splice(index, 1);
                }
              }
              const result = this.processMessageContent(data, previousContent);
              if (result.activity) {
                agentActivity.push(result.activity);
                previousContent = result.newContent;
              }
            }
            break;

          default:
            break;
        }

        if (stop) {
          break;
        }

        index++;
      }

      if (agentOutputs.length > 0 && agentActivity.length > 0) {
        agentActivity[agentActivity.length - 1].input = agentOutputs.join(', ');
      }
    } catch (error) {
      LHTLogger.error('Error processing messages:', error);
      throw error;
    }

    return [agentActivity, index, previousContent];
  };

  async runAgent({ input = {}, saveResponse = true, workerRecordId = null }) {
    const startTime = Date.now();
    try {
      if (workerRecordId) {
        this.sessionService.setupSession({
          supervisorName: this.agent.name,
          workerRecordId,
          saveResponse,
        });
      }

      const inputs = {
        messages: [
          {
            role: 'user',
            content: JSON.stringify(Utils.cleanUpAgentInput(input)),
          },
        ],
      };

      try {
        await this.agent.invoke(inputs);
      } catch (err) {
        await this.sessionService.saveSessionData();
        LHTLogger.error('Error invoking agent:', err);

        if (err instanceof InterruptError) {
          LHTLogger.info(
            'AgentFactory',
            'Agent execution interrupted by user.',
            err.__interrupt__
          );
        } else {
          throw err;
        }
      }

      const lastActivity = this.sessionService.agentActivities.at(-1);
      const output =
        lastActivity?.output ||
        lastActivity?.userFeedbackRequest?.feedbackPrompt ||
        '';

      await this.mem0.addAgentMemories(inputs.messages);
      Object.entries(this.mem0.tokenUsage).forEach(([model, data]) => {
        if (typeof data !== 'object') return;
        this.sessionService.updateTokenUsage(
          model,
          data.prompt || 0,
          data.completion || 0,
          data.type,
          data.total_tokens || 0
        );
      });

      if (lastActivity?.status === ActivityStatus.SUCCEEDED) {
        await this.mem0.addAgentMemories([
          { role: 'assistant', content: output },
        ]);
        Object.entries(this.mem0.tokenUsage).forEach(([model, data]) => {
          if (typeof data !== 'object') return;
          this.sessionService.updateTokenUsage(
            model,
            data.prompt || 0,
            data.completion || 0,
            data.type,
            data.total_tokens || 0
          );
        });
      }

      let sessionServiceData = null;
      if (lastActivity?.status === ActivityStatus.HUMAN_FEEDBACK_REQUIRED) {
        sessionServiceData = await this.sessionService.saveSessionData();
      }

      return {
        output,
        usage: this.sessionService.usage,
        data: this.sessionService.agentActivities,
        status:
          lastActivity?.status === ActivityStatus.SUCCEEDED
            ? ActivityStatus.COMPLETED
            : ActivityStatus.HUMAN_FEEDBACK_REQUIRED,
        sessionData: sessionServiceData,
      };
    } catch (error) {
      LHTLogger.error('Error in agent generate:', error?.message || error);
      const errorActivity = {
        agent_id: this.agent?.agentId || null,
        name: this.agent?.name || this.rootAgentName || 'Unknown Agent',
        status: ActivityStatus.FAILED,
        input: JSON.stringify({
          ...input,
          files: input.files ? input.files.map((f) => f.name) : undefined,
        }),
        output: '',
        errorMessage: error?.message || 'An unexpected error occurred.',
        duration: Date.now() - startTime,
        type: 'AGENT',
        usage: null,
        creditUsage: null,
        cost: null,
        modelDetails:
          this.sessionService.agentModelMapping[this.agent?.name] || null,
        userFeedbackRequest: null,
      };
      await this.sessionService.addAgentActivity(errorActivity);

      return {
        output: error.message || 'An unexpected error occurred.',
        usage: this.sessionService.usage,
        data: this.sessionService.agentActivities,
        status: ActivityStatus.ERRORED,
      };
    }
  }

  async runAgentAsynchronously(data) {
    try {
      const response = await this.runAgent(data);
      LHTLogger.info('Asynchronous agent generate completed:', response);
      await new RabbitMqController().insertInQueue({
        exchangeName: Config.AGENT_CREW_COMPLETION_EXCHANGE,
        queueName: Config.AGENT_CREW_COMPLETION_QUEUE,
        queueData: {
          workerRecordId: data.workerRecordId,
          tenantId: this.tenantId,
          completionData: response,
        },
      });
    } catch (error) {
      LHTLogger.error(
        'Error in asynchronous agent generate:',
        error?.message || error
      );
    }
  }

  async generate({ async = true, ...data }) {
    if (async) {
      setImmediate(async () => {
        await this.runAgentAsynchronously(data);
      });
      return {
        output: 'Agent crew execution started asynchronously.',
        usage: {},
        data: [],
        status: ActivityStatus.IN_PROGRESS,
      };
    }
    return await this.runAgent(data);
  }

  httpTool(toolObject) {
    const tools = (toolObject?.data?.requests || []).map((req) => {
      let bodyValue = {};
      let queryParamValues = {};
      let headerValues = {};
      let inputSchema = {};

      if (req.body) {
        if (req.body?.mode === 'Manual') {
          bodyValue = req.body?.value || {};
        } else {
          inputSchema['body'] = SandboxManager.mapInputSchemaToZod(
            req.body?.inputSchema || {}
          ).describe('Body of the HTTP request');
        }
      }

      if (req.queryParams) {
        const qpSchema = {};
        Object.entries(req.queryParams).forEach(([key, value]) => {
          if (value.mode === 'Manual') {
            queryParamValues[key] = value.value;
          } else {
            let type = value.type || 'string';
            qpSchema[key] =
              type === 'number'
                ? z.number().describe(value.description || '')
                : z.string().describe(value.description || '');
          }
        });
        if (Object.keys(qpSchema).length > 0) {
          inputSchema['queryParams'] = z
            .object(qpSchema)
            .describe('Query parameters for the HTTP request');
        }
      }

      if (req.headers) {
        const headersSchema = {};
        Object.entries(req.headers).forEach(([key, value]) => {
          if (value.mode === 'Manual') {
            headerValues[key] = value.value;
          } else {
            headersSchema[key] = z.string().describe(value.description || '');
          }
        });
        if (Object.keys(headersSchema).length > 0) {
          inputSchema['headers'] = z
            .object(headersSchema)
            .describe('Headers for the HTTP request');
        }
      }

      if (Object.keys(req.pathParams).length > 0) {
        const pathParamsSchema = {};
        Object.entries(req.pathParams).forEach(([key, value]) => {
          pathParamsSchema[key] = z.string().describe(value.description || '');
        });
        inputSchema['pathParams'] = z
          .object(pathParamsSchema)
          .describe('Path parameters for the HTTP request');
      }

      return tool(
        async ({ queryParams, body, headers, pathParams }, config) => {
          try {
            const request = {
              method: req.method || 'GET',
              url: req.url.replaceAll(/\{\{(\w+)\}\}/g, (_, key) => {
                return pathParams && pathParams[key] ? pathParams[key] : '';
              }),
              params: { ...(queryParams || {}), ...queryParamValues },
              data: {
                ...(body || {}),
                ...(typeof bodyValue === 'string'
                  ? JSON.parse(bodyValue || '{}')
                  : {}),
              },
              headers: {
                'Content-Type': 'application/json',
                ...(headers || {}),
                ...headerValues,
              },
            };

            if (config?.toolCall?.id) {
              this.httpInputActivity[config?.toolCall?.id] = request;
            }

            const response = await axios(request);
            return JSON.stringify({
              status: response.status,
              data: response.data,
            });
          } catch (err) {
            return `HTTP request failed: ${err.message}`;
          }
        },
        {
          name: (req.name || 'http_tool').replace(/[^a-zA-Z0-9_-]/g, '_'),
          description: `A tool to make HTTP requests. ${
            req.description || ''
          }`.trim(),
          schema: z.object(inputSchema),
        }
      );
    });
    return tools;
  }

  googleSearchTool(toolObject) {
    return tool(
      async ({ query }) => {
        const result = await MultiAgentService.googleSearch({
          query: query,
          tenantId: this.tenantId,
        });
        if (result.usage) {
          for (const [model, tokens] of Object.entries(result.usage)) {
            if (model && tokens) {
              this.sessionService.updateTokenUsage(
                model,
                Number(tokens.prompt || 0),
                Number(tokens.completion || 0)
              );
            }
          }
        }
        return result;
      },
      {
        name: toolObject.name,
        description: toolObject.description,
        schema: z.object({
          query: z.string().describe('Search query to be executed'),
        }),
      }
    );
  }

  knowledgeBaseSearchTool(toolObject) {
    return tool(
      async ({ query }) => {
        try {
          const { data: response } = await axios.post(
            `${Config.QUERY_ENGINE_MICROSERVICE}/internal/contexts/search`,
            {
              knowledgeBases: (toolObject?.data?.knowledgeBases || []).map(
                (kb) => kb.value
              ),
              query: query,
              json: toolObject?.data?.json ?? false,
              summarize: false,
              metadata: true,
              maxSize: toolObject?.data?.maxTokens,
              service: this.serviceApp,
            },
            {
              headers: {
                'Content-Type': 'application/json',
                'x-secret-key': Config.INTERNAL_SECRET_KEY,
              },
              params: {
                tenantId: this.tenantId,
                platformId: this.platformId,
                projectId: this.projectId,
              },
            }
          );
          return response?.['responseData'] || {};
        } catch (err) {
          return `HTTP request failed: ${err.message}`;
        }
      },
      {
        name: toolObject.name,
        description: toolObject.description,
        schema: z.object({
          query: z
            .string()
            .describe(
              'Query to be executed against the knowledge base to get context'
            ),
        }),
      }
    );
  }

  deepResearchTool(toolObject) {
    const normalizeFilterConfig = (filterConfig) => ({
       /**
       * Filter output with configurable options.
       *
       * Args:
       *   outputData: List of output items from deep research
       *   filterConfig: Object with options:
       *     - consolidate_reasoning (bool): Merge all reasoning summaries into one
       *     - mcp_call_text_only (bool): Keep only extracted text from mcp_call outputs
       *     - include_mcp_list_tools (bool): Include tool listing entries
       *     - include_mcp_call_name (bool): Include the 'name' field in mcp_call entries
       *     - include_web_search_call (bool) : Merge all sources/refernces used into one
       */
      consolidate_reasoning: true,
      mcp_call_text_only: true,
      include_mcp_list_tools: false,
      include_mcp_call_name: true,
      include_web_search_call: true,
      ...(filterConfig || {}),
    });
    const handleWebSearchCallItem = (item, urls, seenUrls) => {
      const action = item?.action;
      if (!action || typeof action !== 'object') return;
      if (action.type !== 'open_page' && action.type !== 'find_in_page') return;
      const url = action.url;
      if (!url || seenUrls.has(url)) return;
      seenUrls.add(url);
      urls.push(url);
    };
    const appendConsolidatedUrls = (config, urls, filteredOutput) => {
      if (!config.include_web_search_call) return;
      if (!urls.length) return;
      filteredOutput.push({ type: 'web_search_call', urls });
    };
    const extractTextFromOutput = (output) => {
      /**
       * Helper to extract text content from structured mcp_call output.
       * Handles various output formats including JSON strings and objects.
       * Note: output is always a string from the MCP call.
       */
      if (typeof output === 'string') {
        try {
          const parsed = JSON.parse(output);
          if (typeof parsed === 'object' && parsed !== null) {
            if (parsed.results) {
              const results = parsed.results;
              if (Array.isArray(results)) {
                const textParts = [];
                for (const r of results) {
                  if (typeof r === 'object' && r !== null) {
                    const title = r.title || '';
                    const text = r.text || '';
                    textParts.push(`- ${title}: ${text}`);
                  }
                }
                return textParts.join('\n');
              }
            }
            return parsed.text || parsed.content || String(parsed);
          }
          return String(parsed);
        } catch (e) {
          return output;
        }
      } else {
        return String(output);
      }
    };
    const filterOutput = (outputData, filterConfig = null) => {
      if (!Array.isArray(outputData)) {
        return { filteredOutput: outputData, urls: [] };
      }
      const config = normalizeFilterConfig(filterConfig);
      const filteredOutput = [];
      const reasoningSummaries = []; // For consolidation
      const urls = [];
      const seenUrls = new Set();
      for (const item of outputData) {
        if (typeof item !== 'object' || item === null) {
          continue;
        }
        const itemType = item.type;
        if (itemType === 'mcp_list_tools' && config.include_mcp_list_tools) {
          filteredOutput.push(item);
        } else if (itemType === 'reasoning') {
          const summaryList = item.summary || [];
          if (Array.isArray(summaryList) && summaryList.length > 0) {
            const hasText = summaryList.some(
              (s) => typeof s === 'object' && s !== null && s.text
            );
            if (hasText) {
              if (config.consolidate_reasoning) {
                reasoningSummaries.push(...summaryList);
              } else {
                filteredOutput.push({
                  type: 'reasoning',
                  summary: summaryList,
                });
              }
            }
          }
        } else if (itemType === 'mcp_call') {
          const output = item.output;
          if (output !== undefined && output !== null) {
            if (config.mcp_call_text_only) {
              const extractedText = extractTextFromOutput(output);
              const mcpCallEntry = {
                type: 'mcp_call',
                output: extractedText,
              };
              if (config.include_mcp_call_name && item.name) {
                mcpCallEntry.name = item.name;
              }
              filteredOutput.push(mcpCallEntry);
            } else {
              const mcpCallEntry = {
                type: 'mcp_call',
                output: output,
              };
              if (config.include_mcp_call_name && item.name) {
                mcpCallEntry.name = item.name;
              }
              filteredOutput.push(mcpCallEntry);
            }
          }
        } else if (itemType === 'web_search_call') {
          if (config.include_web_search_call) {
            handleWebSearchCallItem(item, urls, seenUrls);
          }
        }
      }
      if (config.consolidate_reasoning && reasoningSummaries.length > 0) {
        const consolidatedText = reasoningSummaries
          .map((s) => s.text)
          .filter(Boolean)
          .join('\n\n');
        if (consolidatedText) {
          filteredOutput.unshift({
            type: 'reasoning',
            summary: [{ text: consolidatedText, type: 'summary_text' }],
          });
        }
      }
      appendConsolidatedUrls(config, urls, filteredOutput);
      return { filteredOutput, urls };
    };
    return tool(
      async ({ query }) => {
        try {
          const inputMessages = [
            {
              role: 'user',
              content: [{ type: 'input_text', text: query }],
            },
          ];

          const data = {
            model: toolObject.data.model,
            input: inputMessages,
            tenantId: this.tenantId,
          };

          if ('maxTokens' in toolObject.data) {
            data.maxTokens = toolObject.data.maxTokens;
          }

          if ('temperature' in toolObject.data) {
            data.temperature = toolObject.data.temperature;
          }
          if (GEMINI_DEEP_RESEARCH_MODEL.includes(toolObject.data.model)) {
            const thinkingConfig = { includeThoughts: true };
            if ('thinkingBudget' in toolObject.data) {
              thinkingConfig.thinkingBudget = toolObject.data.thinkingBudget;
            } else {
              thinkingConfig.thinkingLevel = 'high';
            }
            data.thinkingConfig = thinkingConfig;
          }

          if ('tools' in toolObject.data) {
            const tools = toolObject.data.tools.map((tool) => {
              if (tool == 'code_interpreter' || tool == 'code_execution') {
                return {
                  type: tool,
                  container: {
                    type: 'auto',
                  },
                };
              } else if (tool == 'knowledge_base') {
                return {
                  type: 'mcp',
                  // eslint-disable-next-line camelcase
                  server_label: 'internal_file_lookup',
                  // eslint-disable-next-line camelcase
                  server_url: Config.MCP_SERVER_URL,
                  // eslint-disable-next-line camelcase
                  require_approval: 'never',
                  headers: {
                    'x-knowledge-base-ids':
                      toolObject?.data?.knowledgeBases
                        ?.map((kb) => kb.value)
                        .join(',') || '',
                    'x-tenant-id': this.tenantId,
                  },
                };
              }
              return { type: tool };
            });
            data.tools = tools;
          }

          if (
            'reasoning' in toolObject.data &&
            'summary' in toolObject.data.reasoning &&
            toolObject.data.reasoning.summary != 'none'
          ) {
            data.reasoning = toolObject.data.reasoning;
          }

          const response = await this._makeQueryEngineRequest(data);
          if (!GEMINI_DEEP_RESEARCH_MODEL.includes(toolObject.data.model)) {
            const filterConfig = toolObject.data.outputFilter || {};
            let filteredOutput = response?.responseData?.output;
            let urls = [];

            if (filteredOutput) {
              const result = filterOutput(filteredOutput, filterConfig);
              filteredOutput = result.filteredOutput;
              urls = result.urls;
            }

            let outputText = response?.responseData?.output_text;
            if (outputText && urls.length) {
              const urlsBlock = urls.map((u) => `- ${u}`).join('\n');
              outputText = `${outputText}\n\nSources:\n${urlsBlock}`;
            }

            return { data: outputText || filteredOutput };
          }

          let content = response?.responseData?.content ?? '';
          const sources = response?.responseData?.sources ?? [];

          if (Array.isArray(sources) && sources.length) {
            const lines = sources
              .map((s) => {
                const title = s?.title || 'Source';
                const url = s?.url || '';
                return url ? `- ${title}: ${url}` : null;
              })
              .filter(Boolean);

            if (lines.length) {
              content = `${content}\n\nSources:\n${lines.join('\n')}`;
            }
          }

          return { data: content };
        } catch (err) {
          return `HTTP request failed: ${err.message}`;
        }
      },
      {
        name: toolObject.name,
        description: toolObject.description,
        schema: z.object({
          query: z
            .string()
            .describe('Query to be executed to perform the deep search'),
        }),
      }
    );
  }

  async resumeAgent({
    userFeedbackResponse = null,
    workerRecordId,
    saveResponse = true,
    sessionData,
  }) {
    LHTLogger.info('AgentFactory', 'resumeAgentCrew', {
      userFeedbackResponse,
      workerRecordId,
      saveResponse,
      sessionData,
    });

    try {
      if (workerRecordId) {
        this.sessionService.setupSession({
          supervisorName: this.agent.name,
          workerRecordId,
          saveResponse,
          userFeedback: userFeedbackResponse,
        });
      }

      await this.sessionService.loadSessionData(sessionData);

      try {
        await this.agent.invoke(new Command({ resume: true }));
      } catch (err) {
        await this.sessionService.saveSessionData();
        LHTLogger.error('Error invoking agent:', err);

        if (err.__interrupt__) {
          LHTLogger.info(
            'AgentFactory',
            'Agent interrupted with response:',
            err.__interrupt__
          );
        } else {
          throw err;
        }
      }

      const lastActivity = this.sessionService.agentActivities.at(-1);
      const output =
        lastActivity?.output ||
        lastActivity?.userFeedbackRequest?.feedbackPrompt ||
        '';

      await this.mem0.addAgentMemories([
        { role: 'user', content: userFeedbackResponse?.userFeedback },
      ]);
      Object.entries(this.mem0.tokenUsage).forEach(([model, data]) => {
        if (typeof data !== 'object') return;
        this.sessionService.updateTokenUsage(
          model,
          data.prompt || 0,
          data.completion || 0,
          data.type,
          data.total_tokens || 0
        );
      });

      if (lastActivity?.status === ActivityStatus.SUCCEEDED) {
        await this.mem0.addAgentMemories([
          { role: 'assistant', content: output },
        ]);

        Object.entries(this.mem0.tokenUsage).forEach(([model, data]) => {
          if (typeof data !== 'object') return;
          this.sessionService.updateTokenUsage(
            model,
            data.prompt || 0,
            data.completion || 0,
            data.type,
            data.total_tokens || 0
          );
        });
      }

      let sessionServiceData = null;
      if (lastActivity?.status === ActivityStatus.HUMAN_FEEDBACK_REQUIRED) {
        sessionServiceData = await this.sessionService.saveSessionData();
      }

      const status =
        lastActivity?.status === ActivityStatus.SUCCEEDED
          ? ActivityStatus.COMPLETED
          : ActivityStatus.HUMAN_FEEDBACK_REQUIRED;

      return {
        output,
        usage: this.sessionService.usage,
        data: this.sessionService.agentActivities,
        status,
        sessionData: sessionServiceData,
      };
    } catch (error) {
      LHTLogger.error('Error in agent generate:', error);
      return {
        output: error.message || 'An unexpected error occurred.',
        usage: this.sessionService.usage,
        data: this.sessionService.agentActivities,
        status: ActivityStatus.ERRORED,
      };
    }
  }

  async resumeAgentAsynchronously({
    userFeedbackResponse = null,
    workerRecordId,
    saveResponse = true,
    sessionData,
  }) {
    try {
      const response = await this.resumeAgent({
        userFeedbackResponse,
        workerRecordId,
        saveResponse,
        sessionData,
      });
      LHTLogger.info('Asynchronous agent resume completed:', response);
      await new RabbitMqController().insertInQueue({
        exchangeName: Config.AGENT_CREW_COMPLETION_EXCHANGE,
        queueName: Config.AGENT_CREW_COMPLETION_QUEUE,
        queueData: {
          workerRecordId,
          tenantId: this.tenantId,
          completionData: response,
        },
      });
    } catch (error) {
      LHTLogger.error(
        'Error in asynchronous agent resume:',
        error?.message || error
      );
    }
  }

  async resumeAgentCrew({
    userFeedbackResponse = null,
    workerRecordId,
    saveResponse = true,
    sessionData,
    async = false,
  }) {
    LHTLogger.info(
      'AgentFactory',
      'resumeAgentCrew',
      { userFeedbackResponse },
      'Esakki'
    );

    if (async) {
      setImmediate(async () => {
        await this.resumeAgentAsynchronously({
          userFeedbackResponse,
          workerRecordId,
          saveResponse,
          sessionData,
        });
      });
      return {
        output: 'Agent crew execution resumed asynchronously.',
        usage: {},
        data: [],
        status: ActivityStatus.IN_PROGRESS,
      };
    }
    return await this.resumeAgent({
      userFeedbackResponse,
      saveResponse,
      workerRecordId,
      sessionData,
    });
  }

  scratchpadObjectToTools(scratchpad) {
    const getAllScratchpadContent = tool(
      async () => {
        return await scratchpad.getAll();
      },
      {
        name: `get_all_${scratchpad.name}_scratchpad`,
        description: `Retrieve all content from the ${scratchpad.name} scratchpad.`,
        schema: z.object({}), // no inputs
      }
    );

    const addToScratchpad = tool(
      async ({ content }) => {
        return await scratchpad.add(content);
      },
      {
        name: `add_to_${scratchpad.name}_scratchpad`,
        description: `Add content to the ${scratchpad.name} scratchpad.`,
        schema: z.object({
          content: z.any().describe('Content to add to the scratchpad'),
        }),
      }
    );

    const getScratchpadContent = tool(
      async () => {
        return await scratchpad.get();
      },
      {
        name: `get_${scratchpad.name}_scratchpad`,
        description: `Retrieve content from the ${scratchpad.name} scratchpad.`,
        schema: z.object({}), // no inputs
      }
    );

    const updateToScratchpad = tool(
      async ({ oldContent, newContent }) => {
        return await scratchpad.update(oldContent, newContent);
      },
      {
        name: `update_${scratchpad.name}_scratchpad`,
        description: `Update content in the ${scratchpad.name} scratchpad.`,
        schema: z.object({
          oldContent: z.any().describe('Existing content to replace'),
          newContent: z.any().describe('New content to store'),
        }),
      }
    );

    return [
      getAllScratchpadContent,
      addToScratchpad,
      getScratchpadContent,
      updateToScratchpad,
    ];
  }
}
