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
        int ans;
        int cnt=0;
        int j=0;
       for(int i=0;i<n;){
        
        ans=a[i];
       
        if(ans==0){
            cnt++;
            i++;
        }
        else{
            for( j=i+1;j<n;j++){
                ans=ans&a[j];
                if(ans==0){
                    cnt++;
                    break;
                }
            }
             i=j+1;
        }
       
        if(j>=n){
            break;
        }
       }
        if(cnt==0){
            cnt++;
        }
        cout<<cnt<<"\n";
    }
}