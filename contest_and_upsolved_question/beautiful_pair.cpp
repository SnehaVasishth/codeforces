#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        vector<int>a(n);
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            ll rem= a[i]%x;
            mp[rem].push_back(i);
        }
        unordered_map<pair<int,int>,int>beautiful;
ll cnt=0;
    for(int i=0;i<n;i++){
        ll rem= a[i]%x;
        if(mp.find(x-rem)!=mp.end()){
            for(auto it:mp[x-rem]){
                ll sec= a[it];
                ll diff= abs(a[i]-sec);
                if(diff % y==0){
                if(i>it){
                    beautiful.insert({it,i});
                }
                else if(i<it){
                    beautiful.insert({i,it});
                }
                }
            }
        }
        else if(rem==0){
            for(auto it:mp[0]){
                 

                if(it !=i){
                    ll sec= a[it];
                ll diff= abs(a[i]-sec);
                if(diff % y==0){
                     if(i>it){
                    beautiful.insert({it,i});
                }
                else{
                    beautiful.insert({i,it});
                }
                }
                }
            }
        }
    }

    for(auto it:beautiful){
        cout<<it.first<<" "<<it.second<<"\n";
    }

    
    cout<<beautiful.size()<<"\n";

    }
}