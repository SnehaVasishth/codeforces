#include <bits/stdc++.h>
using namespace std;

int solve(int n,int k,vector<int>&a){
    bool flag=0;
    if(k>=2)
    return flag;
    else{
        for(int i=1;i<n;i++){
            if(a[i]>=a[i-1])
            continue;
            else{
                flag=1;
                break;
            }
        }
    }

    return flag;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int ans=solve(n,k,a);
        if (ans==0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

    }
}