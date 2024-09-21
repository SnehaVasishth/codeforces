#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){

    int t;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        vector<ll>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
ll res=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
               ll sum= a[i]+a[j];
               ll diff= abs(a[i]-a[j]);

               if((sum % x ==0 ) && (diff % y==0)){
                res++;
               }
            }
        }
        cout<<res<<"\n";
    }
}