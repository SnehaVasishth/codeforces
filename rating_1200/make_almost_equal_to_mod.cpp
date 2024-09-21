#include<bits/stdc++.h>
#define ll long long

using namespace std;
int main(){

    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<ll>v(n);

    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    ll res=2;
    while(1){
        unordered_set<ll>st;
        for(int i=0;i<n;i++){
            st.insert(v[i]%res);
        }
        if(st.size()==2){
            break;
        }
        res*=2;
    }
    cout<<res<<"\n";
}
}