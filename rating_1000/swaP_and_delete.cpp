#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll n=s.size();
        string p (n,'0');
        ll ans=0;
        ll cnt1=0,cnt0=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                cnt1++;
            }
            else{
                cnt0++;
            }
        }

        for(ll i=0;i<n;i++){
            if(s[i]=='1' && cnt0>0){
                p[i]='0';
                cnt0--;

            }
            else if(s[i]=='1' &&cnt0==0){
                ans=n-i;
                break;
            }
            if(s[i]=='0' && cnt1>0){
                p[i]='1';
                cnt1--;
            }
            else if(s[i]=='0' && cnt1==0){
                ans=n-i;
                break;
            }

        }
        cout<<ans<<"\n";
    }
}