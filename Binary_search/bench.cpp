#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n,m;
    cin>>n>>m;
    vector<ll>a(n);
  ll maxi=0;
  ll an,b;
    for(int i=0;i<n;i++){
        cin>>a[i];
        maxi=max(maxi,a[i]);
}
b=maxi+m;

ll i=0,j=b;
while(i<=j){
    ll mid=(i+j)/2;
    ll cnt=m;
    // cout<<" mid "<<mid<<"\n";
    for(int i=0;i<n;i++){
        if(cnt==0){
            // cout<<"break\n";
            break;
        }
        else if(a[i]>=mid){
            // cout<<"continue\n";
            continue;
        }
        else if(a[i]<mid){
            cnt-=(min((mid-a[i]),cnt));
            // cout<<cnt<<"\n";
        }
        
    }
    if(cnt==0){
        j=mid-1;
        // cout<<" cnt=0 "<<j<<"\n";
    }
    else if(cnt>0){
        i=mid+1;
        // cout<<"cnt> "<<i<<"\n";
    }
}
an=max(maxi,i);
cout<<an<<" "<<b<<"\n";


}