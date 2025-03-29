#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<ll>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        bool flag=0;
        ll ans=0;
        if(k==n){
            ll j=1;
            for(int i=1;i<n;i+=2){
                if(v[i]!=j){
                    flag=1;
                    ans=j;
                    break;
                 

                }
                j++;


            }
            if(flag==0){
                ans=((n/2)+1);
            }
        }
        else{

            for(int i=1;i<=(n-k+1);i++){
                if(v[i]!=1){
                    flag=1;
                    ans=1;
                    break;
                }

            }
            if(flag==0){
                ans=2;
            }
        }

        cout<<ans<<"\n";
    }
}