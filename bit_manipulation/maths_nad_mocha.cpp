#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        int ans;

        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i==0){
                ans=a[0];
            }
            else{
                ans=ans&a[i];
            }
        }
        cout<<ans<<"\n";
    }
}