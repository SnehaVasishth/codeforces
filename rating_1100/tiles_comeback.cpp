#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v[i]=x;
            mp[x].push_back(i);
        }
        if(mp[v[0]].size()>=k && v[n-1]==v[0]){
            cout<<"YES\n";
        }
        else if(mp[v[0]].size()>=k && mp[v[n-1]].size()>=k){
            int m= mp[v[n-1]].size();
            if(mp[v[0]][k-1]< mp[v[n-1]][m-k]){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            cout<<"NO\n";
        }
    }
}