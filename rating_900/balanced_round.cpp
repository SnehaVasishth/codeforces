#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int maxi= 0;
        int cnt=1;
        sort(v.begin(),v.end());
        for(int i=1;i<n;i++){
            if((v[i]-v[i-1])<=k){
                cnt++;
                maxi=max(maxi,cnt);

            }
            else{
                cnt=1;
            }

        }
        maxi=maxi==0?1:maxi;
        cout<<(n-maxi)<<"\n";

    }
}