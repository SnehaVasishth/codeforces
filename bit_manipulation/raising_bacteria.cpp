#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll x;
    cin>>x;
    ll y=x;
    int cnt=0;
    while(x>1){
        x=x/2;
        cout<<"x "<<x<<"\n";
        cnt++;
    }
    ll num=1;
    cout<<"c bnt "<<cnt<<"\n";
    for(int i=1;i<=cnt;i++){
        num*=2;
        cout<<"num "<<num<<"\n";
    }
    ll ans = y-num+1;
    cout<<ans<<"\n";
}