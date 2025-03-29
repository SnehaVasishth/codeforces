#include<bits/stdc++.h>

using namespace std;
#define ll long long


bool traverse(int node,vector<vector<int>>&edge,vector<bool>&boost,vector<bool>&vis,int act_energy,int curr_energy){
    vis[node]=1;
    // cout<<" cur node "<<node<<" "<<"cur energy "<<curr_energy<<"\n";
    for(auto &it:edge[node]){
        
        if(vis[it]==0){
            if(curr_energy>0 && boost[it]==0){
                if(traverse(it,edge,boost,vis,act_energy,curr_energy-1)==false){
                    // cout<<"sneha fasle\n";
                return false;
                }

            }
            else if(curr_energy>0 && boost[it]==1){
                if(traverse(it,edge,boost,vis,act_energy,act_energy)==false){
                    // cout<<"ashi false\n";
                    return false;
                }
            }
            else 
            return false;
        }
       
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>energy(k);
        for(int i=0;i<k;i++){
            cin>>energy[i];
        }
        vector<vector<int>>edge(n+1);
        for(int i=0;i<m;i++){
            int u;
            int v;
            cin>>u>>v;
            edge[u].push_back(v);
            edge[v].push_back(u);


        }

        vector<bool>boost(n+1,0);

        for(int i=0;i<k;i++){
            boost[energy[i]]=1;
        }
        int ans=INT_MAX;
        int l=1,r=n;
        while(l<=r){
            int mid=l+(r-l)/2;
            vector<bool>vis(n+1,0);
            if(traverse(1,edge,boost,vis,mid,mid)==false){
                l=mid+1;

            }
            else {
                ans=min(ans,mid);
                // cout<<"ans: "<< ans<<"\n";
                r=mid-1;
            }
        }
        // vector<bool>vis(n+1,0);
        // bool res= traverse(1,edge,boost,vis,2,2);
        // cout<<"res "<<res<<"\n";
        if(ans<1 || ans>n){
            cout<<-1<<"\n";
        }
        else{
            cout<<"actual ans: "<<ans<<"\n";
        }
        
    }
}