#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;

        int n=s.size();
        ll sum=0;
        ll two=0,three=0;

        for(int i=0;i<n;i++){
            sum+=(s[i]-'0');
            if(s[i]=='2') two++;
            if(s[i]=='3') three++;
        }
        int num =sum%9;
        bool flag=0;
        for(ll i=0;i<=(min(9LL,two));i++){
            for(ll j=0;j<=(min(9LL,three));j++){
                if(((sum+i*2+6*j)%9)==0){
                    cout<<"YES\n";
                    
                    flag=1;
                    break;
                }
            }
            if(flag) break;
        }
        if(flag==0)
        cout<<"NO\n";

    }
}