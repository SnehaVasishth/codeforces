#include<bits/stdc++.h>
#define ll long long 

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        ll ans=0;
        ll ans2=n*m;
       ans= ans2/3;

       if((ans*3)!=ans2){
        ans++;
       }


        cout<<ans<<"\n";
    }
}