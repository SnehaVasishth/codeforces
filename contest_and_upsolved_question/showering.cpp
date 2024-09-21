#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(ll n,ll s,ll m,vector<pair<ll,ll>>&v){
    if(v[0].first>=s){
        return true;
    }
    if((m-(v[n-1].second))>=s)
    return true;
    for(int i=0;i<=(n-2);i++){
        if((v[i+1].first)-(v[i].second)>=s){
            return true;
        }
    }
    return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,s,m;
        cin>>n>>s>>m;
        vector<pair<ll,ll>>v(n);
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            v[i].first=x;
            v[i].second=y;
        }

        if(solve(n,s,m,v)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}