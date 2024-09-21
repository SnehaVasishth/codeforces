#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a.begin(),a.end(),greater<ll>());
        sort(b.begin(),b.end(),greater<ll>());
        vector<ll>pre_a(n),pre_b(n);
        pre_a[0]=a[0];
        pre_b[0]=b[0];
        for(int i=1;i<n;i++){
            pre_a[i]=pre_a[i-1]+a[i];
            pre_b[i]=pre_b[i-1]+b[i];
        }
        ll i=0,j=n;
        int l=n-(n/4)-1;
        ll ca=pre_a[l];
        ll cb=pre_b[l];
        while(i<=j){
            ll k=(i+j)/2;
            ll m= (n+k)-(n+k)/4;
            if(m<=k){
                ca=m*100;
                
            }
            else{
                ca=k*100+pre_a[m-k-1];

            }
            cb=pre_b[min(m,n)-1];
            if(ca>=cb){
                j=k-1;
            }
            else
            i=k+1;

        }
        cout<<i<<"\n";

    }
}