#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(vector<ll>&a,string &s){
    int n=a.size();
    int m=s.size();
    unordered_map<int,char>mp;
    unordered_set<char>st;
    if(n!=m)
    return false;
    for(int i=0;i<n;i++){
        if(mp.find(a[i])==mp.end()){
            if(st.count(s[i])==0){
            mp[a[i]]=s[i];
            st.insert(s[i]);
            }
            else if(st.count(s[i])==1){
                return false;
            }
        }
        else if(mp.find(a[i])!=mp.end()){
            if(mp[a[i]]!=s[i])
            return false;
        }
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int m;
        cin>>m;
        while(m--){
            string s;
            cin>>s;
            bool ans=solve(a,s);
            if(ans){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
    }
}