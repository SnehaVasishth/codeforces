#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>v(n);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            while(k--){
                    int x;
                    cin>>x;
                    mp[x]++;
                    v[i].push_back(x);
            }
        }
        bool flag=0;
       for(auto it:v){
        bool valid=true;
        for(auto a:it){
            if(mp[a]==1){
                valid=false;
                break;
            }
        }
        if(valid){
            flag=1;
            break;
        }
       }
       if(flag==1){
        cout<<"YES\n";
       }
      else
        cout<<"NO\n";
       
    }
}