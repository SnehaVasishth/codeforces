#include<bits/stdc++.h>
#define ll long long int

using namespace std;
int main(){
    int MOD= 1e9+7;
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll pairs=(n*(n-1))%MOD;
        ll fact=1;
        for(int i=1;i<=n;i++){
            fact=(fact*i)% MOD;
        }
        ll ans= (pairs*fact)%MOD;
        cout<<ans<<"\n";

    }
}