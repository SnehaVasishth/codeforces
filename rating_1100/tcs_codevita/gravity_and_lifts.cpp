#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long movedown(long long i,long long j, vector<vector<long long>>&matrix,long long n ,long long m,long long &step){
    long long k=i;
    for(k=i+1;k<n;k++){
          step++;
        if(matrix[k][j]==2){
            break;

        }
      
    }
    return k;

}
long long moveup(long long i,long long j, vector<vector<long long>>&matrix,long long n,long long m,long long &step){
    long long k=i-1;
    for(k=i-1;k>=0;k--){
         step++;
        if(matrix[k][j]==2){
            break;
           

        }
       
    }
    return k;
}
long long solve(long long i,long long j,long long destrow,long long destcol,vector<vector<long long>>&matrix,vector<vector<long long>>&dp,long long n,long long m,vector<vector<long long>>&vis){


    // cout<<i<<" "<<j<<" currcordinates\n";
    if(i==destrow && j==destcol){
        return 0;
    }
    if(i<0 || i>=n || j<0 || j>=m|| vis[i][j]==1 || matrix[i][j]==1)
    return 1e9;
    long long stable= matrix[i][j];

    // cout<<stable<<" stability\n";
    if(stable==1)
    return 1e9;
    long long step=0,step1=0;
   if(stable==0){
    vis[i][j]=1;
      i=movedown(i,j,matrix,n,m,step);
   }


   long long left=1e9,right=1e9,up=1e9;

   vis[i][j]=1;

    left= 1+ solve(i,j-1,destrow,destcol,matrix,dp,n,m,vis)+step;
//    cout<<left<<" left \n";
    right= 1+solve(i,j+1,destrow,destcol,matrix,dp,n,m,vis)+step;
//    cout<<right<<" right\n";

    if(i-1>=0 && matrix[i-1][j]==1){
   long long newi =  moveup(i,j,matrix,n,m,step1);
    up=step1+ solve(newi,j,destrow,destcol,matrix,dp,n,m,vis)+step;
    }
  


vis[i][j]=0;

   

 return min({left,right,up});

    

   
}

int main(){
    long long n,m;
    cin>>n>>m;
    vector<vector<long long>>matrix(n,vector<long long>(m));
     vector<vector<long long>>vis(n,vector<long long>(m,0));
    for(long long i=0;i<n;i++){
        for(long long j=0;j<m;j++){
            cin>>matrix[i][j];
        }
    }
    long long startrow,startcol,destrow,destcol;
    cin>>startrow>>startcol;
    cin>>destrow>>destcol;

    for(long long i=0;i<n;i++){
        for(long long j=0;j<m;j++){
            if(i==n-1 && matrix[i][j]==0){
                matrix[i][j]=2;
            }
            else if(matrix[i+1][j]==1 && matrix[i][j]==0)
            matrix[i][j]=2;
        }
    }


 

    vector<vector<long long>>dp(n,vector<long long>(m,-1));


    if(matrix[destrow][destcol]==0 || matrix[destrow][destcol]==1)
    {
        cout<<"Impossible\n";
    }
    else{
      
        cout<<solve(startrow,startcol,destrow,destcol,matrix,dp,n,m,vis)-1<<"\n";
   

    }
}