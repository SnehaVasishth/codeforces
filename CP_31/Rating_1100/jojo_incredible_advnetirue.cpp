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
       ll len=0,cnt=0;

        for(int i=0;i<n;){

            if(s[i]=='1'){
                while(i<n && s[i]=='1'){
                    cnt++;
                    i++;
                }
                len=max(len,cnt);
                cnt=0;
            }
            else{
                i++;
            }
        }

    cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            break;
        }
        cnt++;
    }
    for(int i=n-1;i>=0;i--){
        if(s[i]=='0'){
            break;
        }
        cnt++;
    }

    cnt=min(cnt,n);
    len=max(len,cnt);
    // cout<<cnt<<" "<<len<<"\n"; 

    if(len==n){
        ll ans=n*n;
        cout<<ans<<"\n";
    }
    else{
        len++;
        ll a= len/2;
        ll b= len-a;
        ll ans=a*b;
        cout<<ans<<"\n";
    }

    }

}