#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        pair<ll,ll>a,b,c;
        cin>>a.first>>a.second;
        cin>>b.first>>b.second;
        cin>>c.first>>c.second;
    ll ans1=0,ans2=0;

    if((b.second>=a.second && c.second>=a.second) ||(b.second<=a.second && c.second<=a.second)){
        ans1= min(abs(a.second-b.second),abs(a.second-c.second));
    }
    if((b.first>a.first && c.first>a.first) ||(b.first<a.first && c.first<a.first)){
       ans2= min(abs(b.first-a.first),abs(c.first-a.first));
    }
    ll ans3= ans1 + ans2+1;

    cout<<ans3<<"\n";


}
}