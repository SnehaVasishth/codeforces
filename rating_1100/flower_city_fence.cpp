#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n+1);
        for(int i=1;i<=n;i++){
            cin>>v[i];
        }
        if(v[1]!=n){
            cout<<"NO\n";
           
        }
        else{
        int m=v[1];
        vector<int>ans(m+1,0);
        for(int i=1;i<=n;i++){
            ans[v[i]]++;
        }
        for(int i=m-1;i>=1;i--){
            ans[i]=ans[i]+ans[i+1];
        }
        bool flag=0;
       for(int i=1;i<=n;i++){
        if(ans[i]!=v[i]){
            flag=1;
            cout<<"NO\n";
            break;
        }
       }
       
       if(flag==0)
       cout<<"YES\n";
        }
    }
}