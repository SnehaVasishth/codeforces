#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int maxi= *max_element(v.begin(),v.end());
        int mini= *min_element(v.begin(),v.end());
        int res=0;
        int diff1=0,diff2=0;
        
        if(v[0]==mini || v[n-1]==maxi){
            cout<<(maxi-mini)<<"\n";
        }
        else{
            for(int i=0;i<n;i++){
                if(v[i]==maxi){
                    diff2= v[i]-v[i+1];
                }
                else if(v[i]==mini){
                    diff1= v[i-1]-v[i];
                }
                res= max(diff1,diff2);
            }
            cout<<res<<"\n";
        }
        
    }
}