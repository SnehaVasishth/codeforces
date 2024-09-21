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
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        vector<ll>pre(n);
        pre[0]=a[0];
        for(int i=1;i<n;i++){
            pre[i]=pre[i-1]+a[i];
        }
        ll day=0,pack=0;
        for(int i=n-1;i>=0;i--){
            ll cost=pre[i]+(i+1)*day;
            if((x-cost)>=0){
                ll days=((x-cost)/(i+1))+1;
                pack+=((i+1)*days);
                day+=days;
            }
        }
        cout<<pack<<"\n";
    }
}