#include<bits/stdc++.h>
#define  lli long long int
using namespace std;

int main(){
    lli t;
    cin>>t;
    while(t--){
        lli n,k,a,b;
        cin>>n>>k>>a>>b;
        vector<lli>x(n+1);
        vector<lli>y(n+1);
        for(lli i=1;i<=n;i++){
            cin>>x[i]>>y[i];
        }
        lli price= abs(x[a]-x[b])+abs(y[a]-y[b]);
        lli pricea=LLONG_MAX/2;
        lli priceb=LLONG_MAX/2;
        
        for(lli i=1;i<=k;i++){
            pricea= min(pricea,abs(x[i]-x[a])+abs(y[i]-y[a]));
            priceb= min(priceb,abs(x[i]-x[b])+abs(y[i]-y[b]));

        }
        cout<<min(price,pricea+priceb)<<"\n";

    }
}