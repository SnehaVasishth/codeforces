#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int ans=0;
        for(int i=0;i<n/2;i++){
            ans= __gcd(ans,abs(v[i]-v[n-1-i]));
        }
        cout<<ans<<"\n";

    }
}