#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        vector<int>a(n+1,1);
       int e=-1;
       for(int i=x+1;i<=n;i++){
        a[i]=e;
        e*=(-1);
       }
       e=-1;
       for(int i=(y-1);i>=1;i--){
        a[i]=e;
        e*=(-1);
       }
        for(int i=1;i<=n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}