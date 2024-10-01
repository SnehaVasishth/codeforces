#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll solve(ll k,ll n){
    ll num=k;
    while(num<n){
        num*=k;
    }
    if(num>n){
        num/=k;
    }
    return num;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll cnt=0,num=0;
        if(n==k || (n==1)){
            cnt=1;
        }
        else if(n<k || (k==1)){
            cnt=n;
        }
        
        else{
        while(n!=0){
            if(n<k){
                cnt+=n;
                n=0;
            }
            else{
            num= solve(k,n);
            n=n-num;
            cnt++;
            }
        }
        }
        cout<<cnt<<"\n";
    }
}

