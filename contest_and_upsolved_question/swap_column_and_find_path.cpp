#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>>a(2,vector<int>(n));
        ll sum=0;
        
        for(int i=0;i<2;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }

        vector<int>best(n);
        vector<int>full(n);
        for(int i=0;i<n;i++){
            best[i]=max(a[0][i],a[1][i]);
            full[i]=a[0][i]+a[1][i];
            sum+=best[i];
        }

        ll ans=INT_MIN;
        
        for(int i=0;i<n;i++){
            ans=max(ans,sum+full[i]-best[i]);
        }

        cout<<ans<<"\n";


    }
}