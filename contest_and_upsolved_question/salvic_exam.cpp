#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(int i,int j,string &s,string &t){
    if(j<0)
    return true;
    if(i<0 && j>=0)
    return false;

    if(s[i]==t[j]){
        if(solve(i-1,j-1,s,t)==true)
        return true;
    }
    else if(s[i]=='?'){
        s[i]=t[j];
        if(solve(i-1,j-1,s,t)==true)
        return true;
    }
    else if(s[i]!=t[j]){
        if(solve(i-1,j,s,t)==true)
        return true;
    }
    return false;
}

int main(){
    int c;
    cin>>c;
    while(c--){
        string s,t;
        cin>>s>>t;
        int i= s.size()-1;
        int j=t.size()-1;

        bool ans =solve(i,j,s,t);
        if(ans==0){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            for(int i=0;i<s.size();i++){
                if(s[i]=='?'){
                    s[i]='a';
                }
            }
            cout<<s<<"\n";
        }
    }
}