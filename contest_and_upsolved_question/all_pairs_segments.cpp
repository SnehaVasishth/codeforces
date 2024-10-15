#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<ll>cordinates(n);
        vector<ll>query(q);
        for(int i=0;i<n;i++){
            cin>>cordinates[i];
        }
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        unordered_map<ll,ll>mp;
        for(int i=0;i<=(n-2);i++){
            ll seg= (ll)(n-1-i)+(ll)(n-1-i+1)*i;
            mp[seg]++;
            // seg= (ll)(n-1-(i+1))+(ll)(n-1-(i+1)+1)*i;
            // mp[seg]++;
            ll element= cordinates[i+1]-cordinates[i]-1;
            seg=(ll)(n-1-(i+1)+1)*(i+1);
            mp[seg]+=element;
        }
        mp[n-1]++;
        for(int i=0;i<q;i++){
            cout<<mp[query[i]]<<" ";
        }
        cout<<"\n";
    }
}
