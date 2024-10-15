#include<bits/stdc++.h>
#define ll long long


using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll b,c,d;
        cin>>b>>c>>d;
        ll a=0ll;
        for(ll i=0;i<64;i++){
            ll aa=(1ll<<i);
            ll bb= (aa&b)?(aa):(0ll);
            ll cc=(aa&c)?(aa):(0ll);
            ll dd=(aa&d)?(aa):(0ll);
            if(((aa|bb)-dd)==((aa&cc))){
                a+=aa;
            }
        }
        if((a|b)==(d+(a&c))){
            cout<<a<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }
    }
}