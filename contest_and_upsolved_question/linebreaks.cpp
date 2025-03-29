#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        ll cnt=0,ans=0;
        int i=0;
        while(i<n && (a[i].size()+cnt)<=m){
            ans++;
            cnt+=a[i].size();
            i++;
        }

        cout<<ans<<"\n";
    }


}