#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(vector<ll>&a,vector<ll>&prefix,string &s){
    int n=a.size();
    int i=0;
    int j=n-1;
    ll ans=0;
    while(i<j){
        if(s[i]=='R'){
            i++;
        }
        if(s[j]=='L'){
            j--;
        }
        if( s[i]=='L' && s[j]=='R'){
           ans+=(prefix[j+1]-prefix[i]);
           i++;
           j--;
        }

    }
    
    cout<<ans<<"\n";
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>a(n),prefix(n+1,0);

        for(int i=0;i<n;i++){
            cin>>a[i];
            prefix[i+1]=prefix[i]+a[i];

        }
        string s;
        cin>>s;

        solve(a,prefix,s);
    }
}