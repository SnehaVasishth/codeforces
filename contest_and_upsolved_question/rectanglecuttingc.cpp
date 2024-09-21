#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        bool flag=0;
        if((a&1)==0){
            ll len= a/2;
            ll nayi=b*2;
            if((len!=b && nayi!=a)){
                flag=1;
            }
        }
        if((b&1)==0 && flag==0){
            ll len= b/2;
            ll nayi= a*2;
            if((len!=a) && (nayi!=b)){
                flag=1;
            }
           
        }
        if(flag==0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
}