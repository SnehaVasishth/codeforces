#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,l,r;
        cin>>n>>l>>r;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int i=0,j=0;
        ll sum=0;
        int cnt=0;
        while(i<n){
            
           
           
                while(sum<l && j<n && i<n){
                    
                    sum+=v[j];
                    j++;
                }
                if(sum>=l && sum<=r){
                    cnt++;
                   i=j;
                    sum=0;
                }
                else{
                    sum-=v[i];
                    i++;
                    if(j<i){
                        j=i;
                    }
                    
                    
                
            }
        }
        cout<<cnt<<"\n";
    }
}