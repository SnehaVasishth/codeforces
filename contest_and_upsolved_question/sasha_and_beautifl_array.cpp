#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll sum=0;
    for(int i=1;i<n;i++){
        sum+=(a[i]-a[i-1]);
    }
    cout<<sum<<"\n";
    }
}