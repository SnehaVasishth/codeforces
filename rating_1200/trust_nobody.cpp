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

        int ans=-1;

        for(int j=0;j<=n;j++){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(a[i]>j){
                    cnt++;
                }
            }
            if(cnt==j){
                ans=cnt;
                break;
            }
        }
        cout<<ans<<"\n";

    }
}