#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<pair<int,int>>a(4);
       for(int i=0;i<4;i++){
        cin>>a[i].first;
        cin>>a[i].second;
       }
       ll side=0;
       for(int i=0;i<4;i++){
        for(int j=i+1;j<4;j++){
            if(a[i].first==a[j].first){
                side= abs(a[i].second-a[j].second);
                break;
            }
            else if(a[i].second==a[j].second){
                side=abs(a[i].first-a[j].first);
                break;
            }
        }
       }

       ll ans= side*side;
       cout<<ans<<"\n";
    }
}