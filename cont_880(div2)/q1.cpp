#include<bits/stdc++.h>
using namespace std;
int  main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a((n+1),0);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            if(x<n){
                a[x]++;
            }
            else{
                a[n]=INT_MAX;
            }
        }
        bool flag=true;
        for(int i=1;i<=n;i++){
            if(a[i]>a[i-1]){
                flag=false;
                break;
            }
        }
        if(flag==false){
            cout<<"NO"<<"\n";
        }
        else{
            cout<<"YES"<<"\n";
        }
    }
}