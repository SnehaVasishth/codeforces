#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b;
        cin>>a>>b;
        if(b==1){
            cout<<"NO"<<"\n";
        }
        else{
        ll x= a*b;
        ll y= a;
        ll z= (b+1)*a;
        cout<<"YES\n";
        cout<<x<<" "<<y<<" "<<z<<"\n";
        }
        
    }
}