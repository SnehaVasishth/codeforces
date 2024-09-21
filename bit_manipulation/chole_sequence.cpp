#include<bits/stdc++.h>
#define ll long long
using namespace std;

int solve(ll l,ll r ,ll k,ll n){
    ll m= l+(r-l)/2;
    if(k<m){
      return  solve(l,m-1,k,n-1);
    }
    else if(k>m){
        return solve(m+1,r,k,n-1);
    }
    else{
        return n;
    }
}

int main(){
    ll n,k;
    cin>>n>>k;
    ll sz=1;
    for(int i=1;i<n;i++){
        sz=sz*2+1;
    }

    cout<<solve(1,sz,k,n);
    cout<<"\n";
}