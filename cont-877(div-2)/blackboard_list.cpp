#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        bool flag=false;
        int maxi=INT_MIN;
        int ans;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[i]=x;
            if(x<0){
                flag=true;
                ans=a[i];

            }
            if(a[i]>maxi){
                maxi=a[i];
            }
        }
        if(flag==true){
            cout<<ans<<"\n";
        }
        else if(flag==false){
            cout<<maxi<<"\n";
        }
    }
}