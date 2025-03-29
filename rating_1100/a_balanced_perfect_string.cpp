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
        unordered_set<char>st(s.begin(),s.end());
        int k=st.size();
        bool flag=0;

        for(int i=0;i<n;i++){
            if((i+k)<n && s[i]!=s[i+k])
            {
                flag=1;
                break;
            }
            else if((i+k)>=n)
            break;
        }
        if(flag==1)
        cout<<"NO\n";
        else{
            cout<<"YES\n";
        }
    }
}