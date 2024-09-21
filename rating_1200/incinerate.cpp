#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<pair<ll,ll>>a(n);
        vector<ll>h(n),p(n);
        for(int i=0;i<n;i++){
            cin>>a[i].first;
      
        }
        for(int i=0;i<n;i++){
            cin>>a[i].second;
        }
  
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        h[i]=a[i].first;
    }
      p[n-1]=a[n-1].second;
    for(int i=n-2;i>=0;i--){
        p[i]=min(a[i].second,p[i+1]);
    }
    // for(int i=0;i<n;i++){
    //     cout<<" p[i] "<<p[i]<<" ";
    // }
    // for(int i=0;i<n;i++){
    //     cout<<" h[i ] "<<h[i]<<" ";
    // }
    // cout<<"\n";
    // cout<<"\n";
bool flag=0;

    ll cost=k;
    while(k>0){
        int idx= upper_bound(h.begin(),h.end(),cost)-h.begin();
        //  cout<<"idx  "<<idx<<"\n";
        if(idx==n){
            flag=1;
            break;
        }
        k-=p[idx];
      
        cost+=k;
        //  cout<<"k "<<k<<" cost "<<cost<<"\n";
    }
    if(flag)
    cout<<"Yes\n";
    else
    cout<<"NO\n";
}
}