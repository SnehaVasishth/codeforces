#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll ans=0;
        ll res= (4*n)-2;
        if(k==res){
            ans= n*2;
        }
        else if((k&1)==0){
            ans= k/2;
        }
        else{
            ans= (k/2)+1;
        }
        cout<<ans<<"\n";

    }
    
}