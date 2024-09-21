#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
ll n;
cin>>n;

n= max(n,6LL);
n=((n&1)!=0)?n+1:n;
ll ans= (n/2)*5;
cout<<ans<<"\n";
    }
}