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
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        vector<ll>prefix(n);
        prefix[0]=a[0];
        for(int i=1;i<n;i++){
            prefix[i]=prefix[i-1]+a[i];
        }
        ll maxi=0;
        for(int i=0;i<=(n-2);i++){
            ll a= prefix[i];
            ll b=  prefix[n-1]-prefix[i];
            maxi=max(maxi,__gcd(a,b));
        }
        cout<<maxi<<"\n";
    }
}