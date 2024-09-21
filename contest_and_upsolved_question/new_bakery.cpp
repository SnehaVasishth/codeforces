#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,a,b;
        cin>>n>>a>>b;

        if((b-a)>0){
            ll cal= b-a;
            if(cal>=n){
                cal=b-n;
                ll res= (b*(b+1)/2) - (cal*(cal+1)/2);
                cout<<res<<"\n";
            }
            else{
                ll res = (b*(b+1)/2)-(a*(a+1)/2) + (n-cal)*a;
                cout<<res<<"\n";
            }
        }
        else{
            ll res= n*a;
            cout<<res<<"\n";
        }
    }
}