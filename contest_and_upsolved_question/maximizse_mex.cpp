#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,x;
        cin>>n>>x;
        vector<ll>a(n);
        unordered_map<ll,ll>mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]<=n){
                mp[a[i]]++;
            }
        }

        ll mex=0;
        for(int i=0;i<=n;i++){
            if(mp[i]>0){
                if(mp[i]>1){
                    mp[i+x]+=(mp[i]-1);
                    mp[i]=1;
                }
            }
            else{
                mex=i;
                break;
            }
        }
        cout<<mex<<"\n";
    }
}