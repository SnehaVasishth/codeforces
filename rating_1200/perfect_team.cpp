#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int q;
    cin>>q;
    while(q--){
     ll c,m,x;
        cin>>c>>m>>x;
        ll sum=c+m+x;
        ll one= sum/3;
        ll ans= min(one,min(c,m));
        cout<<ans<<"\n";
    }
}