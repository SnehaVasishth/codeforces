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
        unordered_map<int,vector<int>>mp;

        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]].push_back(i);
        }
        // for(auto it:mp){
        //     cout<<it.first<<"---"<<"\n";
        //         for(int i=0;i<it.second.size();i++){
        //             cout<<it.second[i]<<" ";
        //         }
        //         cout<<"\n";
        // }
        int idx=0,ans=0;
        for(int i=1;i<n;i++){
            if(a[i-1]>a[i]){
                for(int j=idx;j<=(i-1);j++){
                    bool flag=0;
                    if(a[j]!=0){
                       int si=mp[a[j]].size();
                       int num=a[j];
                    for(int k=0;k<si;k++){
                        // cout<<a[j]<<"  sneha\n";
                        // cout<<mp[num][k]<<"  kyanbhi\n";
                        a[mp[num][k]]=0;
                        flag=1;
                    }
                    }
                    if(flag==1) {
                        // cout<<a[j]<<" aashi\n";
                        ans++;
                    }
                }
                idx=i;
            }
        }
        cout<<ans<<"\n";
    }
}