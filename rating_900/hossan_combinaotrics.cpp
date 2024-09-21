#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll cnt1=0,ans=0,cnt2=0;

        int maxi= *max_element(a.begin(),a.end());
        int mini=*min_element(a.begin(),a.end());
        for(int i=0;i<n;i++){
            if(maxi==a[i]){
                cnt1++;
            }
            if(mini==a[i]){
                cnt2++;
            }
        }
        if(maxi==mini){
            ans= ((((n-1)*n)/2)*2);
        }
        else{
            ans= cnt1*cnt2*2;
        }
        cout<<ans<<"\n";
    }

}