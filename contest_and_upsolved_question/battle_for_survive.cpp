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
        ll maxi=-1,idx=-1;
        ll sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            
        }
        
        ll res= sum-a[n-2]-a[n-1];
        ll ans= a[n-1]-(a[n-2]-res);
        cout<<ans<<"\n";
    }
}