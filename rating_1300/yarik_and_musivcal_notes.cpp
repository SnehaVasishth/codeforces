#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);

        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        map<int,int>mp;
        ll ans=0;
        for(int i=0;i<n;i++){
            ans+=mp[a[i]];
            if(a[i]==1){
                ans+=mp[2];
            }
            else if(a[i]==2){
                ans+=mp[1];
            }
            mp[a[i]]++;
        }
        cout<<ans<<'\n';
    }
}
