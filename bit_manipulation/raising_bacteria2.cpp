#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll x;
    cin>>x;
    ll cnt=0;
    // while(x){
    //     cnt+=(x&1);
    //     x=x>>1;

    // }
    // cout<<cnt<<"\n";
    cout<<__builtin_popcount(x)<<"\n";
}