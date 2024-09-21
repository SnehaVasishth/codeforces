#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool solve(vector<ll>&a,int n){
    unordered_set<ll>st;
    if(n==1){
        if(a[0]==1){
            return true;
        }
        return false;
    }
    st.insert(a[0]);
    for(int i=1;i<n;i++){
        int num=a[i];
        if((st.count(num-1)==1) || (st.count(num+1)==1)){
            st.insert(a[i]);
        }
        else{
            return false;
        }
    }
    return true;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        bool ans= solve(a,n);
        if(ans){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}