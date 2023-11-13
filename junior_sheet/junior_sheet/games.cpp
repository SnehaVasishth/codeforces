#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    unordered_map<int,int>mp1;
    unordered_map<int,int>mp2;
    for(int i=0;i<n;i++){
        int h,g;
        cin>>h>>g;
        mp1[h]++;
        mp2[g]++;
    }
    int res=0;
    for(auto x:mp1){
        if(mp2.find(x.first)!=mp2.end()){
            res= res+x.second* mp2[x.first];
        }
    }
    cout<<res<<"\n";
}