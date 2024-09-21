#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,h;
        cin>>n>>h;
        vector<ll>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll l=1,r=h;
        
        while(l<=r){
            ll m=l+((r-l)/2);
            ll total=0;
            for(ll i=0;i<=(n-2);i++){
                ll diff=a[i+1]-a[i];
                if(diff<=m){
                        total+=diff;
                }
                else
                total+=m;
            }
              total+=m;
              if(total>=h){
                r=m-1;
              }
              else
              l=m+1;

        }
        cout<<l<<"\n";
      

    }
}