#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    unordered_map<int,int>mp;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        mp[i]=a;
}
int m;
cin>>m;
for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    if(x>1 && x<n){
        mp[x-1]=mp[x-1]+y-1;
        mp[x+1]=mp[x+1]+mp[x]-y;
        mp[x]=0;
    }
    if(x==1){
         mp[x+1]=mp[x+1]+mp[x]-y;
        mp[x]=0;

    }
    if(x==n){
         mp[x-1]=mp[x-1]+y-1;
         mp[x]=0;

    }
}
for(int i=1;i<=n;i++){
    cout<<mp[i]<<"\n";
}

}