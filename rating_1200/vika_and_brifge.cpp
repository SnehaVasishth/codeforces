#include<bits/stdc++.h>
#define ll long long
using namespace std;


  

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            
        }
        for(int i=0;i<n;i++){
            mp[a[i]].push_back(i);
        }
        // for(auto it:mp){
        //     cout<<"it.first"<<it.first<<"\n";
        //     for(int i=0;i<it.second.size();i++){
        //         cout<<"it.second "<<it.second[i]<<"\n";
        //     }
        // }

        int mini=n;
        int left=0;
        for(auto it:mp){
            int max1=0,max2=0;
            // cout<<" inside it.first "<<it.first<<"\n";
            left=it.second[0];
            if(left>max1){
                    max2=max1;
                    max1=left;
                }
               else if(left<max1 && left>max2){
                    max2=left;
                }

            for(int i=0;i<=(it.second.size()-1);i++){
                if(i==it.second.size()-1){
                    left= (n-(it.second[i])-1);
                }
                else
                 left=(it.second[i+1]-it.second[i]-1);
                if(left>=max1){
                    max2=max1;
                    max1=left;
                }
               else if(left<max1 && left>max2){
                    max2=left;
                }
                // cout<<" max2 "<<max2<<" max1 "<<max1<<"\n";
            }
            int half=max1/2;
            max1=max(half,max2);
            mini=min(mini,max1);
            // cout<<" first "<<it.first<<" "<<mini<<"\n";
        }
        cout<<mini<<"\n";

      
}
}