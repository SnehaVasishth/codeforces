#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,m,q;
        cin>>n>>m>>q;
        ll t1,t2,d;
        cin>>t1>>t2>>d;
        ll one = abs(d-t1);
        ll two= abs(d-t2);
        ll ans= 0;
    
        ll maxi= max(t1,t2);
        ll mini=min(t1,t2);
        if(d>maxi){
            ans=n-maxi;
        }
        else if(d<mini){
            ans=mini-1;
        }
        else{
            ans= (maxi-mini)/2 ;
        }
    cout<<ans<<"\n";

    }
}
