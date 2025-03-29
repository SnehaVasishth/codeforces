#include<bits/stdc++.h>
#define ll long long
using namespace std;

unordered_map<string,ll>dp;

string get_key(int op,vector<ll>&v){
    string key=to_string(op)+'|';
    for(int i=0;i<v.size();i++)
    key+=to_string(v[i]);
    return key;
}


ll solve(int op,vector<ll>v){
    if(v.size()==1)
    return v[0];

    string s= get_key(op,v);
    if(dp.find(s)!=dp.end())
    return dp[s];
    ll sum1=LLONG_MIN,sum2=LLONG_MIN,sum3=LLONG_MIN;
    sum1=accumulate(v.begin(),v.end(),0LL);
    vector<ll>a=v;
    reverse(a.begin(),a.end());
    vector<ll>t(v.size()-1);
    for(int i=1;i<v.size();i++){
        t[i-1]=v[i]-v[i-1];
    }
    if(op==-1|| op==2){
        sum2=solve(1,a);
        sum3= solve(2,t);
        return dp[s]=max(sum1,max(sum2,sum3));
    }
    sum3=solve(2,t);
    return dp[s]=max(sum1,sum3);
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
        cout<<solve(-1,v)<<"\n";
    }
}