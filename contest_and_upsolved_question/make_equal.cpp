#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
int t;
cin>>t;
while(t--){
    ll n;
    cin>>n;
    vector<ll>a(n);
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
    }

    ll buk= (sum)/n;
    ll collect=0;
    bool flag=0;
    for(int i=0;i<n;i++){
        if(a[i]> buk){
            collect+=(a[i]-buk);
        }
        else if((collect<=0 &&  (a[i]!=buk)) || ((a[i]+collect)< buk)){
            flag=1;
            break;
        }
        
        else if((a[i]<buk) && collect>=1){
            collect-= (buk-a[i]);
        }
        
        // cout<<"c:"<<collect<<"\n";
    }
    if(flag==1){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
}
}