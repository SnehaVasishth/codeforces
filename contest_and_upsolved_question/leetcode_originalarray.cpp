#include<bits/stdc++.h>

using namespace std;
 vector<int> findArray(vector<int>& pref) {
        int n= pref.size();
        vector<int>arr(n);
        arr[0]=pref[0];
        int x = arr[0];
        for(int i=1;i<n;i++){
            arr[i]= x ^ pref[i];
            x= x ^ arr[i];
        }
        return arr;
    }

    int main(){
        int n;
        cin>>n;
        vector<int>ans(n);
        vector<int>pref(n);
        for(int i=0;i<n;i++){
            cin>>pref[i];
        }
        ans= findArray(pref);
        for(int i=0;i<n;i++){
            cout<<ans[i];
        }

    }