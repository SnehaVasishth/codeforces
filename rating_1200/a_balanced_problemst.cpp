#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll x,n;
        cin>>x>>n;
        
        ll ans=1;

        for(ll i=1;i*i<=x;i++){
            if(x%i==0){
                if(n<=(x/i))
                ans=max(ans,i);
                if(n<=i)
                ans=max(ans,x/i);
            }
        }
        cout<<ans<<"\n";

        
    }
}