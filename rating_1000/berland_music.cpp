#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>p(n);
        for(int i=0;i<n;i++)
        cin>>p[i];
        string s;
        cin>>s;

        map<int,int>mp0,mp1;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            mp0[p[i]]=i;
        }
        else if(s[i]=='1'){
            mp1[p[i]]=i;
        }
    }
    

    int idx=1;
    vector<int>ans(n);
    for(auto it:mp0){
        ans[it.second]=idx;
        idx++;

    }
    for(auto it:mp1){
        ans[it.second]=idx;
        idx++;
    }
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<"\n";


}

}