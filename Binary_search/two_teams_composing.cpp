#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check(int size,unordered_map<int,int>&mp){
        ll second_team=0,left=0,first_team=0;
        for(auto it:mp){
            if(it.second>=size){
                 second_team=size;
                 left=it.second-size;
                if(left>0){
                        first_team=1;
                }
                first_team+=(mp.size()-1);
                if(first_team>=size){
                    return true;
                }
            }
        }
        return false;


}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>a(n);
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }

        int i=1,j=n/2;
        while(i<=j){
            int mid=(i+j)/2;
            if(check(mid,mp)){
                i=mid+1;
            }
            else
            j=mid-1;
        }
        cout<<j<<"\n";
    }
}