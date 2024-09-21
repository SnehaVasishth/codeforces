#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n);
  ll maxi=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxi=max(maxi,a[i]+m);
}

ll i=0,j=maxi;
while(i<=j){
    ll mid=(i+j)/2;
    ll cnt=m;
    for(int i=0;i<n;i++){
        if(cnt==0){
            break;
        }
        else if(a[i]>=mid){
            continue;
        }
        else if(a[i]<mid){
            cnt-=(min((mid-a[i]),cnt));
        }
    }
    if(cnt==0){
        j=mid-1;
    }
    else if(cnt>0){
        i=mid+1;
    }
}
cout<<i<<" "<<maxi<<"\n";


}