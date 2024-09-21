#include<bits/stdc++.h>

using namespace std;
vector<int>solve(vector<int>&arr){
    int n=arr.size();
    vector<int>ans;
    map<int,vector<int>>mp;
    for(int i=1;i<=(n-1);i++){
        mp[arr[i]].push_back(i);
    }

    

    for(auto it:mp){

        if((it.second).size()==1){
            return {-1};
        }
        else{

            int s= (it.second).size();
            for(int i=1;i<s;i++){
                ans.push_back((it.second)[i]);
            }
            ans.push_back((it.second)[0]);
        }
    }
    return ans;

       
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n+1);
        for(int i=1;i<=n;i++){
            cin>>arr[i];
        }
        vector<int>res=solve(arr);
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<"\n";
    }
}