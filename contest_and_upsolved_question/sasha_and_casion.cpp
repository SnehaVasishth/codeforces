#include<bits/stdc++.h>
#define ll long long
using namespace std;


void solve(ll k,ll x,ll a){
    ll curr=1;
    ll nextime=0;
    ll aa=a;
    for(int i=2;i<=x;i++){
        nextime= (curr)/(k-1);
        nextime++;
        curr+=nextime;
        if(curr>a){
            cout<<"NO\n";
            return;
        }


    }

    a-=curr;
    if(a<0){
        cout<<"NO\n";
        return;
    }
    a*=k;
    if(a>aa){
        cout<<"YES\n";
    return;
    }
    cout<<"NO\n";
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll k,x,a;
        cin>>k>>x>>a;
        solve(k,x,a);
    }
}