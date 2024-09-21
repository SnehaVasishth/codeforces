#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,c;
        cin>>n>>c;
        vector<ll>a(n);
        ll squared=0,para=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            squared+=(a[i]*a[i]);
            para+=a[i];
        }
        ll val= -((c-squared)/4);
        ll k=para*para;
        ll z=(4*n*val);
        ll vanu=k-z;

        ll r1= (-1*(para)- sqrt(vanu))/(2*n);
        ll r2=(-1*(para)+ sqrt(vanu))/(2*n);
        r1>=r2?cout<<r1<<"\n":cout<<r2<<"\n";
    }
}