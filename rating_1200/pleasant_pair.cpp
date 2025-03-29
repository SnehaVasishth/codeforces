#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>a(n);
        for(ll i=0;i<n;i++)
        cin>>a[i];

        ll cnt=0;

        ll last= 4*n*n;
       
        for(ll i=1;i<=n;i++){
            ll num=a[i-1];
            for(ll j=num;j<=2*n;j+=num){
                ll k= j-i;
                
                if(k>=1 && k<=n && (((ll)a[k-1]*num)==(k+i)) && k>i){
                    cnt++;
                  
                }
                if(k>n)
                break;
               
                
            }
        }
        cout<<cnt<<"\n";
    }
}