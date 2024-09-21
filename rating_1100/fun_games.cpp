#include<bits/stdc++.h>

using namespace std;
void solve(string &s,string &t){
    int n=s.size();
    if(s==t){
        cout<<"YES\n";
        return;
    }
    for(int i=0;i<n;i++){
        if(s[i]=='1'){
            cout<<"YES\n";
            return;
        }
        else {
            if(s[i]!=t[i]){
                cout<<"NO\n";
                return;
            }
        }
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s,t;
        cin>>s>>t;
        solve(s,t);
    }
}