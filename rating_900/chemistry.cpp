#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    vector<int>cnt(26,0);
    for(int i=0;i<n;i++){
        char c= s[i];
        cnt[s[i]-'a']++;
    }
    sort(cnt.begin(),cnt.end());
    int flag=0;
    for(int i=0;i<cnt.size()&&k>0;i++){
        if(cnt[i]>0){
            while(cnt[i]!=0 && k!=0){
                cnt[i]--;
                k--;
            }
        }
    }

    for(int i=0;i<cnt.size();i++){
        if(cnt[i]%2!=0 && flag==0){
            flag=1;
        }
        else if(flag==1 && cnt[i]%2!=0){
            flag=2;
            break;
        }
    }
    if(flag==0 || flag==1){
        cout<<"YES\n";
    }
    else {
        cout<<"NO\n";
    }

}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}