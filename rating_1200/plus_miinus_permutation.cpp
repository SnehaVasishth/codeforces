#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;

        ll x_index= (n/x);
        ll y_index=(n/y);

        // cout<<"xidx "<<x_index<<"yidx  "<<y_index<<"\n";

        ll hcf= __gcd(x,y);
        // cout<<"hcf "<<hcf<<"\n";

        ll lcm= ((x*y)/(hcf));
        // cout<<"lcm  "<<lcm<<"\n";

       ll common= (n/lcm);
       ll R= x_index-common;
       ll B= y_index-common;

        // cout<<"rr "<<R<<"  bbb  "<<B<<"\n"; 

        ll sumx=0,sumy=0,cnt1=n,cnt2=1,res=0;

        sumx= (R*((2*n)-R+1))/2;
        sumy= (B*(B+1))/2;

       
        res= (sumx-sumy);
        cout<<res<<"\n";

    }
}