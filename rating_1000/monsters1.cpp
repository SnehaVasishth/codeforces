#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>ans;
        vector<pair<int,int>>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second=(i+1);
        }
sort(a.begin(),a.end());
for(int i=0;i<n;i++){
    if(a[i].first==k){
        ans.push_back(a[i].second);
    }
}
for(int i=0;i<n;i++){
    if(a[i].first==k){
        continue;
    }
    ans.push_back(a[i].second);
}
 for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}