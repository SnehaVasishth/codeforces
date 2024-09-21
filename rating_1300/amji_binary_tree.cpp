#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int>adj[n+1];
        for(int i=1;i<=n;i++){
            int a,b;
            cin>>a>>b;
            adj[i].push_back(a);
            adj[i].push_back(b);
        }

        queue<pair<int,int>>q;
        q.push({1,0});
        int ans=INT_MAX;

        while(!q.empty()){
            int node=q.front().first;
            int dis=q.front().second;
            q.pop();

            int left=adj[node][0];
            int right=adj[node][1];
            if(left!=0){
                if(s[node-1]=='L')
                q.push({left,dis});
                else{
                    q.push({left,dis+1});
                }
            }
            if(right!=0){
                if(s[node-1]=='R')
                q.push({right,dis});
                else{
                    q.push({right,dis+1});
                }
            }
            if(left==0 && right==0){
                ans=min(ans,dis);
            }
        }
        cout<<ans<<"\n";
    }
}