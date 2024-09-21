#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string a;
        string b;
        cin>>a>>b;

        int n=a.size();
        int m= b.size();
        vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
        ll ans=0;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(a[i-1]==b[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=0;
                }
                ans=max(ans,dp[i][j]);
            }
        }
    ll res= 2*ans;
    res=n+m-res;
    cout<<res<<"\n";


    }
}