#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,x;
        cin>>n>>k>>x;
        vector<int>a(n);
        vector<ll>prefix(n);
        ll sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        sort(a.begin(),a.end(),greater<int>());
        ll s=0;
        for(int i=n-1;i>=0;i--){
            s+=a[i];
            prefix[i]=s;

        }
        // for(auto t:a){
        //     cout<<t<<" ";
        // }
        // cout<<"\n";
        // for(auto t:prefix){
        //     cout<<t<<" ";
        // }
        // cout<<"\n";
        ll totalsum=prefix[0];
        ll restsum;
       if(x>n-1){
        int y= n-1;
        restsum= 0;
       } 
       else{ 
        restsum= prefix[x];
       }
        ll negativesum= totalsum-restsum;
        ll currsum= restsum-negativesum;

        ll maxi=INT_MIN;
        maxi=max(maxi,currsum);
    int idx=0;
   
        while((k>=1) ){
           if(idx+1>=0 && idx+1<=n-1) totalsum=prefix[idx+1];
           else{
            totalsum=0;
           }
           if(idx+1+x>=0 && idx+1+x<=n-1) restsum=prefix[idx+1+x];
           else{
            restsum=0;
           }
            negativesum= totalsum-restsum;
            
            currsum= restsum -negativesum;
            maxi=max(maxi,currsum);
           

            k--;
            idx++;
            }


        
        cout<<maxi<<"\n";

    }
}