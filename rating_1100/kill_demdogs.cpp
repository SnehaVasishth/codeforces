#include<bits/stdc++.h>
#define ll long long
using namespace std;
int mod=1e9+7;

ll modexp(ll a,ll b){

    ll ans=1;
    while(b>0){
        if(b&1){
            ans=(ans*a)%mod;
        }
        a=(a*a)%mod;
        b=b>>1;
    }
    return ans%mod;

}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans=0;
        

        ll term1= ((((((n%mod)*((n+1)%mod))%mod)*((2*n+1)%mod))%mod)*modexp(6,mod-2))%mod;
        ll term2= (((((((n-1)%mod)*((n)%mod))%mod)*((2*n-1)%mod))%mod)*modexp(6,mod-2))%mod;
        ll term3= (((((n-1)%mod)*(n%mod))%mod)*modexp(2,mod-2))%mod;

        ans = (((term1+term2)%mod)+term3)%mod;

        ans= (ans*2022)%mod;
        cout<<ans<<"\n";
    }
}