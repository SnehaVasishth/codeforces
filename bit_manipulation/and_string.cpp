#include<bits/stdc++.h>
#define ll long long
using namespace std;
int  main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll ans=(1LL<<31)-1;
        vector<ll>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            
            if(a[i]!=i){
                ans&=a[i];
            }

        }
        cout<<ans<<"\n";
    }
}

