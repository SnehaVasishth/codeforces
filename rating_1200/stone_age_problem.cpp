#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    vector<ll>a(n);
    ll actual=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        actual+=a[i];
    }
    ll lastvalue=-1,lastime=0;
    vector<ll>update(n,0);
    ll time=1;

    ll original=actual;

   for(int i=1;i<=q;i++){
        int t;
        cin>>t;
        if(t==1){
            ll pos;
            cin>>pos;
            ll x;
            cin>>x;
            ll sum=original;
            if(update[pos-1]>= lastime){
                sum=sum-a[pos-1]+x;
            }
            else if(update[pos-1]<lastime){
                sum=sum-lastvalue+x;
            }
            
            original=sum;
            update[pos-1]=i;
            a[pos-1]=x;
            cout<<sum<<"\n";
        }
        else{
            int x;
            cin>>x;
            ll sum=n*x;
            original=sum;
            lastvalue=x;
            lastime=i;
            cout<<sum<<"\n";

        }
     

    }

}