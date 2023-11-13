#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        vector<ll>pre((n+1),0);
        for(int i=0;i<n;i++){
            pre[i+1]=pre[i]+a[i];
        }
        ll maxi=0;

        for(int i=0;i<=k;i++){
            maxi= max(maxi, pre[n-i]-pre[2*(k-i)]);
        }
        cout<<maxi<<"\n";
    }
}