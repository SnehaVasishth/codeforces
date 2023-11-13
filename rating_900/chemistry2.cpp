#include<bits/stdc++.h>

using namespace std;
void solve(){

    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    unordered_map<char,int>mp;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
    }
    int even=0,odd=0;
    for(auto &it:mp){
        if((it.second)%2==0){
            even++;
        }
        else{
            odd++;
        }
    }
    if(odd>k+1){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
    solve();
    }
}
