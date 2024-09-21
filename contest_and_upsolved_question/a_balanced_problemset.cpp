#include<bits/stdc++.h>
#define ll long long

using namespace std;
int main(){

    ll t;
    cin>>t;
    while(t--){
        ll x,n;
        cin>>x>>n;
        ll result= x/n;
        ll maxi=1;

        if(x%n!=0){

            for(ll j=2;j*j<=result;j++){
                if(x%j==0){
                    maxi=max(maxi,j);
                    
                }
            }

        }
        else{
            maxi=result;
        }

        cout<<maxi<<"\n";
    }

}