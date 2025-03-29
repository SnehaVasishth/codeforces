#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll solve(int i,int j,vector<vector<ll>>&dp,vector<ll>&v){
    if(i>j)
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    ll sum=0,maxi=-1e10;
    for(ll k=i;k<=j;k++){
        if(v[k]<0){
            sum=abs(v[k])+solve(i,k-1,dp,v);
        }
        else{
            sum=abs(v[k])+solve(k+1,j,dp,v);
        }
        maxi=max(maxi,sum);
    }

    return dp[i][j]=maxi;

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>v(n);
        for(int i=0;i<n;i++)
        cin>>v[i];

        vector<vector<ll>>dp(n,vector<ll>(n,-1));

        cout<<solve(0,n-1,dp,v)<<"\n";

    }
}
