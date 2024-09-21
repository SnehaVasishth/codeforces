#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<ll>a(n+1),v(n+1);
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i>a[i])
        v.push_back(i);
    }
    ll res=0;
   for(int i=1;i<=n;i++){
    if(a[i]>=i)
    continue;
    res+=lower_bound(v.begin(),v.end(),a[i]);
   }
   cout<<res<<"\n";
}
}