#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll>a(n);
        ll sum=0,maxi=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            maxi=max(a[i],maxi);
            sum+=a[i];
        }
        ll ans=1;
        for(int i=1;i<=n;i++){
            ll max_no_grp= (sum+k)/i;
            if(max_no_grp < maxi)
            continue;
            else{
                if((max_no_grp*i)>=sum)
                ans=i;
                
            }
        }
        cout<<ans<<"\n";
    }
}