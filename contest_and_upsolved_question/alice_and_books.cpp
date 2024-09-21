#include<bits/stdc++.h>
#define ll long long
using namespace std;

int index(vector<ll>&a,ll &maxi){
    int n=a.size();
    ll idx=0;
    for(int i=0;i<n;i++){
        if(a[i]>maxi){
            maxi=a[i];
            idx=i;
            // cout<<a[i]<<" "<<maxi<<" "<<idx<<"\n";
        }
    }
return idx;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll maxi1=a[0],maxi2=a[0],idx1=0,idx2=0;
    idx1=index(a,maxi1);
    a[idx1]=INT_MIN;
    idx2=index(a,maxi2);
    // cout<<idx1<<" "<<idx2<<"\n";
       
       
        if((n-1)==idx1){
            ll ans=maxi1+maxi2;
            cout<<ans<<"\n";
        }
        else{
            ll ans= maxi1+a[n-1];
            cout<<ans<<"\n";
        }

    }
}