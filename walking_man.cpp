#include<bits/stdc++.h>
using namespace std;
int bfs(int a,int b,int c,int d){
    queue<pair<int,int>>pq;
    vector<vector<int>>dist(100,vector<int>(100,-1));
    bool visited[100][100];
    for(int i=0;i<100;i++){
        for(int j=0;j<100;j++){
            visited[i][j]=false;
        }
    }
    pq.push({a,b});
   
    dist[a][b]=0;
  
    visited[a][b]=true;
   
    int dx[2]={-1,1};
    
    int dy[2]={0,1};
     
    
    while(pq.empty()==false){
        int x= pq.front().first;
        int y= pq.front().second;
      cout<<x<<"\n"<<y<<"\n";
        pq.pop();
        if(x==c &&y==d){
            cout<<dist[x][y];
        return dist[x][y];
        }
        if((x+1)==c && y==d || (x+1)==c && (y-1)==d|| x==c && (y-1)==d || (x-1)==c && (y-1)==d)
        return -1;
        cout<<"sneha"<<"\n";
        for(int i=0;i<2;i++){
            int row= dx[i]+x;
            int col= dy[i]+y;
            if(visited[row][col]==false){
                visited[row][col]=true;
                dist[row][col]=dist[x][y] +1;
                pq.push({row,col});
            }
              if((x+1)==c && y==d || (x+1)==c && (y-1)==d|| x==c && (y-1)==d || (x-1)==c && (y-1)==d)
        return -1;
        }
    }
    return -1;
}
int main(){
    int t;
    cin>>t;
    while(t--){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<bfs(a,b,c,d)<<"\n";
    }
}