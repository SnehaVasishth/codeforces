#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll a,b,c,d;
        cin>>a>>b>>c>>d;
        ll ans=0;
        if(a==0){
            if(b>0 || c>0 ||d>0){
                ans=1;
            }
            else
            ans=0;
        }
        else if(a>0){
            ans=1;
            a=a-1;
            ans+=(2*min(b,c));
            ans+=a;
            ll now= a+1;
            ll left=max(b,c)-min(b,c);
            if((now+1)>left){
                ans+=left;
                now=now-left;
                ans+=min((now+1),d);
            }
            else if((now+1)<=left){
                ans+=(now+1);
            }
        }
        cout<<ans<<"\n";
    }
}