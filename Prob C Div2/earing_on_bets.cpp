#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll lcm(ll a,ll b){
    return (a*b)/__gcd(a,b);
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>a(n);
        ll pro=1,sum=0;

        for(ll i=0;i<n;i++){
            cin>>a[i];
            pro=lcm(pro,a[i]);
        }
        vector<ll>ans(n);

        for(ll i=0;i<n;i++){
            ans[i]= (pro)/(a[i]);
            sum+=ans[i];
        }
        if(sum>=pro){
            cout<<-1<<"\n";
        }
        else{
            for(ll i=0;i<n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<"\n";
        }
    }
}