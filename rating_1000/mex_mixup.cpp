#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        ll x=0;
       if(((a-1)%4)==0){
        x=a-1;
       }
       else if(((a-1)%4)==1){
        x=1;
       }
       else if(((a-1)%4)==2){
        x=a;
       }
       else if(((a-1)%4)==3){
        x=0;
       }
        ll ans=a;

        
       if(x==b){
        ans=a;
       }
       else if((x!=b)&&((x^b)!=a)){
        ans++;
       }
       else if(((x^b)==a) && (x!=b)){
        ans+=2;
       }
           
        
        cout<<ans<<"\n";
    }
}