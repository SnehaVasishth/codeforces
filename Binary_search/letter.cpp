#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n,m;
    cin>>n>>m;
    ll sum=0;
    vector<ll>a(n),b(m);
    vector<ll>v;
    v.push_back(0);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        v.push_back(sum);
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    for(int i=0;i<m;i++){
        ll idx=lower_bound(v.begin(),v.end(),b[i])-v.begin();
        cout<<idx<<" "<<(b[i]-v[idx-1])<<"\n";
    }
       
}