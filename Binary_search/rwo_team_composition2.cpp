#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }

        int maxcnt=0;
        for(auto it:mp){
            if(it.second>maxcnt){
                maxcnt=it.second;
            }
        }

        int diff=mp.size();
        int ans= max(min(diff-1,maxcnt),min(diff,maxcnt-1));
        cout<<ans<<"\n";
    
    }
}