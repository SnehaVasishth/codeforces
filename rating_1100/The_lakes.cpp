#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>>v(n,vector<int>(m,0));
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        ll dist=0;
        bool flag=0;
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
                
        }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(v[i][j]!=0){
                    q.push({v[i][j],{i,j}});
                    vis[i][j]=true;
                    

                }
                else if(v[i][j]==0){
                    vis[i][j]=true;
                }
            }
            
            }
        

        int x[4]={0,0,-1,1};
        int y[4]={-1,1,0,0};
        while(!q.empty()){
            int a = q.front().first;
            int X= q.front().second.first;
            int Y= q.front().second.second;
            q.pop();
            dist+=a;
            for(int i=0;i<4;i++){
                int x_co= x[i]+X;
                int y_co= y[i]+Y;
                if(x_co >=0 && x_co<n && y_co>=0 && y_co<m && vis[x_co][y_co]==false && v[x_co][y_co]!=0){
                    q.push({v[x_co][y_co],{x_co,y_co}});
                    vis[x_co][y_co]=true;

                }
            }
        }

cout<<dist<<"\n";
    }
}