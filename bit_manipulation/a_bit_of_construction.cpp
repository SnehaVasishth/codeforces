#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        if(n==1){
            cout<<k<<"\n";
        }
        else{
        ll num=log2(k);
        ll ans=pow(2,num);
        cout<<(ans-1)<<" "<<(k-(ans-1))<<" ";
        int left=n-2;
        while(left){
            cout<<0<<" ";
            left--;
        }
        cout<<"\n";
        }
    }
}
