#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        vector<int>v;
        v.push_back(0);
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='R')
            v.push_back(i+1);
        }
        v.push_back(n+1);
        int ans=0;
        for(int i=1;i<v.size();i++){
            ans=max(ans,v[i]-v[i-1]);
        }
        cout<<ans<<"\n";
    }
}