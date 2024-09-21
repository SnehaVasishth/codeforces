#include<bits/stdc++.h>
#define ll long long
using namespace std;
int  main(){
    int t;
    cin>>t;
    while(t--){

        ll n,f,a,b;
        cin>>n>>f>>a>>b;
        ll battery=0;
        vector<ll>arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }

        for(int i=0;i<n;i++){
            if(i==0){
                ll ss=arr[i]*a;
                
                if(ss<=b){
                    battery+=(arr[i]*a);
                }
                else{
                    battery+=b;
                }

            }
            else{
            ll k= (arr[i]-arr[i-1])*a;
            
            if(k<=b){
                battery+=k;
            }
            else{
                battery+=b;
            }
            }
        }
       
        if(battery<f){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }

    }
}