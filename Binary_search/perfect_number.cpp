#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll check(ll num){
    ll ans=0;
    while(num){
        ans+=(num%10);
        num=num/10;
    }
    return ans;
}
int main(){
ll k;
cin>>k;
ll ans=0;
while(k){
     ans++;
    if(check(ans)==10){
        
        k--;
    }
   
}
cout<<ans<<"\n";
}