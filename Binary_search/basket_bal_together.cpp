#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,d;
    cin>>n>>d;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    ll i=0,j=n-1;
    sort(a.begin(),a.end(),greater<ll>());
    ll cnt=0;
    while(i<j){
        ll team= ceil((floor)(d+1)/a[i]);
        // cout<<" team "<<team<<"\n";
        if((j-i+1)>=team){
            cnt++;
        }
        if(team>=1){
            i++;
            team--;
        }
        j=j-team;
        
    }
    if(a[i]>d){
        cnt++;
    }
    cout<<cnt<<"\n";

}