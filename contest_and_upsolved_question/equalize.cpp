#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<ll>a(n);
    set<ll>st;
    for(int i=0;i<n;i++){
        cin>>a[i];
        st.insert(a[i]);
    }
vector<ll>v;
ll ans=0;
for(auto &it: st){
    v.push_back(it);
}
for(int i=0;i<v.size();i++){
    ll it= v[i];
    ll itt=lower_bound(v.begin(),v.end(),v[i]+n)-v.begin();
    ll dis= itt-i;
    ans=max(ans,dis);

}
cout<<ans<<'\n';
}
}