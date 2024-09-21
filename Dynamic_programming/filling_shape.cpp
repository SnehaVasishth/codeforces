#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<ll>p(61,-1);

ll power(ll n){
    if(n==0){
        return 1;
    }
    if(n==1){
        return 2;
    }
    ll x=1;
    if(p[n]!=-1){
        x=p[n];
    }
    else
    x=power(n/2);
    if((n&1)!=1){
     p[n]=(x*x);
    }
    else
     p[n]=(x*x*2);
     return p[n];

}

int main(){
int n;
cin>>n;
if((n&1)!=1){
    cout<<power(n/2)<<"\n";
}
else{
    cout<<0<<"\n";
}

}