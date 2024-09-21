#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>v[m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x;
                cin>>x;
                v[j].push_back(x);
            }
        }
        for(int i=0;i<m;i++){
            sort(v[i].begin(),v[i].end());
        }

        ll ans=0;
        for(int i=0;i<m;i++){
            vector<ll>res(n,0);
            res[n-1]=v[i][n-1];
            for(int j=n-2;j>=0;j--){
                res[j]=res[j+1]+v[i][j];
            }
            for(int j=0;j<=(n-2);j++){
                ans+=(res[j+1]-(ll)(n-1-j)*(v[i][j]));
            }
        }
        cout<<ans<<"\n";
    }
}