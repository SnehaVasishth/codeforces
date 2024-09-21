#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
   map<ll,ll>val,mp;
   mp[0LL]=1LL;

   for(ll i= 1LL;i<=30LL;i++){
    mp[i]=(mp[i-1]*(2LL));
   }

   ll m;
   cin>>m;

   for(int i=0;i<m;i++){
    ll a,b;
    cin>>a>>b;
    if(a==1){
        val[mp[b]]++;
    }
    else{
        for(ll i=30;i>=0;i--){
            if(b>=mp[i] && b!=0){
                if(val.count(mp[i])){
                    b-=(min((b/mp[i]),val[mp[i]]))*(mp[i]);
                }
            }
        }
        if(b==0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
   }
    
}