#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n+1,0);
        vector<int>pos(n+1);
        for(int i=1;i<=n;i++){
            cin>>v[i];
            pos[v[i]]=i;
        }
        int ans= 0;
        for(int i=2;i<=n;i++){
            if(pos[i-1]>pos[i])
            ans++;
        }
        cout<<ans<<"\n";
    }
}