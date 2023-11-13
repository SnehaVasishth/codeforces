#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        map<int,int>mp;
        mp[0]=a[0];
        bool flag=0;
        for(int i=1;i<n;i++){
            if(a[i]>=(mp.rbegin()->second) && flag==0){
                mp[i]=a[i];
               
            }
          else  if(flag==0 && a[i]<=(mp.begin()->second)){
                mp[i]=a[i];
                flag=1;
                
            }

          else  if(flag==1 && a[i]>=(mp.rbegin())->second && a[i]<=(mp.begin()->second)){
                // cout<<mp.rbegin()->second<<"\n";
                mp[i]=a[i];
                

            }
        }
        string str="";
        for(int i=0;i<n;i++){
            if(mp.find(i)!=mp.end()){
                str+='1';
            }
            else{
                str+='0';
            }
        }
        cout<<str<<"\n";
        // for(auto it:mp){
        //     cout<<it.first<<"  "<<it.second<<"\n";
        // }
    }
}