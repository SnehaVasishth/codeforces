#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>a(n+1);
bool flag1=0;
int idx=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==1 && flag1==0){
                flag1=1;
                idx=i;
            }
        }
        bool flag=0;
        ll cnt=0;

        for(int i=n;i>=1;i--){
            if(a[i]==1 && flag==0){
                flag=1;
            }
            else if(a[i]==0 && flag==1 && i>=idx){
                cnt++;
            }
        }
        cout<<cnt<<"\n";

    }
}