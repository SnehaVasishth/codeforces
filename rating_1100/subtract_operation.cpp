#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        set<ll>st;
        vector<ll>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            st.insert(a[i]);
        }bool flag=0;

        for(int i=0;i<n;i++){
            if(st.find(a[i]-k)!=st.end()){
                flag=1;
                break;
            }
        }
        if(flag==1)
        cout<<"YES\n";
        else{
            cout<<"NO\n";
        }
    }
}