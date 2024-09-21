#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    ll sum=0;
    ll x=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        x=(x^a[i]);
    }
    if((sum %360)==0 || (x==0 || sum==0)){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
}