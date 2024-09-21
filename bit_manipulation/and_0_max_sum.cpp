#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll mod=1e9+7;

long long po(ll n,ll k){
    if(k==0)
    return 1;
    if(k==1)
    return n;
    ll num= (po(n,k/2))%mod;
    if((k&1)==0){
        return (((num % mod)*(num% mod))%mod);
    }
    else{
        return (n*(((num % mod)*(num% mod))%mod)%mod);
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll ans= po(n,k)%mod;
        cout<<ans<<"\n";
    }
}