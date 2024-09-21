#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        ll i=0,j=1;
        ll n=s.size();
    ll mini=n;
    bool flag=0;
        while(j<n){
            while(s[i]==s[j] &&(j<n)){
                j++;
                // cout<<"j "<<j<<"\n";
            }
            i=j-1;
            // cout<<"i "<<i<<"\n";
            char el=s[j];
            while(s[j]==el && (j<n)){
                j++;
                // cout<<" andhar j "<<j<<"\n";
            }
            if((s[i]==s[j])&& j<n){
                i=j-1;
                // cout<<" anhdar i "<<i<<"\n";
            }
            else if((s[j]!=s[i])&&(s[i]!=s[j-1])&&(s[j-1]!=s[j])&& (j<n)){
                    mini=min((j-i+1),mini);
                    flag=1;
                    // cout<<" mini "<<mini<<"\n";
            }
        }
        if(flag==0){
            mini=0;
        }
        cout<<mini<<"\n";
    }
}