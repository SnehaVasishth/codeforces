import axios from "axios";

export const code = async (inputs) => {
  const {
    path,
    bucket,
    dataSourceUrl = "http://zbrain-datasrc-ms-srv.zbrain.internal:8000",
    xSecretKey,
    timeoutMs = 60000,
  } = inputs || {};

  if (!path || !bucket) {
    throw new Error("Missing required inputs: path, bucket");
  }
  if (!xSecretKey) {
    throw new Error("Missing required input: xSecretKey");
  }

  const url = `${dataSourceUrl.replace(/\/$/, "")}/add-connector`;

  const payload = {
    connectorType: "file",
    input: {
      file: {
        path,
        bucket,
      },
    },
  };

  const { data } = await axios.post(url, payload, {
    headers: {
      "Content-Type": "application/json",
      "x-secret-key": xSecretKey,
    },
    timeout: timeoutMs,
    maxBodyLength: Infinity,
  });

  const responseData = data?.responseData ?? data;
  const documents = responseData?.documents ?? [];
  const text = documents.map((d) => d?.text).filter(Boolean).join("\n\n");

  return {
    documents,
    text,
    doc_id: responseData?.doc_id ?? null,
    raw: responseData,
  };
};
