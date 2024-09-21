#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll check(ll w,vector<ll>&a,ll c){
    int n=a.size();
    ll sum=0;
    for(int i=0;i<n;i++){
        ll area= (a[i]+(2*w))*(a[i]+(2*w));
        sum+=area;
        if(sum>c){
            return sum;
        }
        
        
    }
    // cout<<" w "<<w<<" sum "<<sum<<"\n";
    return sum;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,c;
        cin>>n>>c;
        vector<ll>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        ll i=0,j=1e9;

        while(i<=j){
            ll mid=(i+j)/2;
            ll val=check(mid,a,c);
            // cout<<" mid "<<mid<<" i "<<i<<" j "<<j<<" val "<<val<<"\n";
            if(val==c){
                cout<<mid<<"\n";
                // cout<<"sneha\n";
                break;
            }
            else if(val>c){
                j=mid-1;
                // cout<<" j aashi "<<j<<"\n";
            }
            else{
                i=mid+1;
                // cout<<" i kanha "<<i<<"\n";
            }
        }

    }
}