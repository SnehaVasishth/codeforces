#include<bits/stdc++.h>

using namespace std;
#define ll long long

ll solve(ll val,ll l1,ll r1,ll l2,ll r2){
    ll minval= l2/val;
    if(l2%val)minval++;
    ll maxval= r2/val;
    ll minrange= max(l1,minval);
    ll maxrange=min(r1,maxval);

    return max(0LL,maxrange-minrange+1);
   
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll k,l1,r1,l2,r2;
        cin>>k>>l1>>r1>>l2>>r2;
        vector<ll>val;
        ll pre=1LL;
        while(pre<=r2){
            val.push_back(pre);
            pre*=k;
        }
        int n=val.size();
        ll ans=0;

        for(int i=0;i<n;i++){
            ans+=solve(val[i],l1,r1,l2,r2);

        }
        cout<<ans<<endl;

    }
}