#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    int x;
    map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        cin>>x;
        mp[x].push_back((i+1));
    }
    int a=mp[1].size();
    int b=mp[2].size();
    int c=mp[3].size();
    int mini= min(a,min(b,c));
    cout<<mini<<"\n";
    for(int i=0;i<mini;i++){
        cout<<mp[1][i]<<" "<<mp[2][i]<<" "<<mp[3][i]<<"\n";
    }
   
}