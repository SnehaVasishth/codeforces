#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int test;
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        string t;
        cin>>t;
        vector<ll>cost(n+1);

        for(int i=n;i>=1;i--){
            cost[i]=i;
            for(int j=i;j<=n;j+=i){
                if(t[j-1]=='1')
                break;
                cost[j]=i;

            }
        }
        ll ans=0;
        for(int i=1;i<=n;i++){
            if(t[i-1]=='0')
            ans+=cost[i];
        }
        cout<<ans<<"\n";
    }
}