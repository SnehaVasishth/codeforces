#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    unordered_map<int,int>mp;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        mp[x]=i;
    }
    for(int i=1;i<=n;i++){
        cout<<mp[i]<<" ";
    }
    cout<<"\n";
}