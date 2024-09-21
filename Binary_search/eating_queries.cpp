#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,q;
        cin>>n>>q;
        vector<ll>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end(),greater<ll>());
        vector<ll>pre(n);
        pre[0]=a[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+a[i];
        }
        while(q--){
          ll x;
          cin>>x;

          int idx=lower_bound(pre.begin(),pre.end(),x)-pre.begin();
          if(idx==n){
            cout<<-1<<"\n";
          }
          else{
            cout<<idx+1<<"\n";
          }

        }
    }
}