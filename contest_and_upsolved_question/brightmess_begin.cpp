#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll sqr(ll n){
    ll l=1,r=n;
    while(l<=r){
        ll mid=l+(r-l)/2;
      
        if(mid>(n/mid))
        r=mid-1;
        else
        l=mid+1;
    }
    return r;
}
int main(){
    int t;
    cin>>t;
    while(t--){
       ll k;
       cin>>k;

       ll l=1, r= 2e18;

       while(l<=r){
        ll mid= l+(r-l)/2;
        ll pos= mid- sqr(mid);
        if(pos>=k)r=mid-1;
        else l=mid+1;
       }

       cout<<l<<"\n";

    }
}