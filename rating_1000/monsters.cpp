#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>ans;
        vector<int>a(n);
    

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[i+1]=a[i];
            
        }
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            if(a[i]==k){
                ans.push_back(mp[k]);
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]==k){
                continue;
            }
            ans.push_back(mp[a[i]]);
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}