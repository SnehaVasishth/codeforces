#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<pair<ll,ll>>vec;
        ll pro=1,mini=1e8;
        ll m=n;
        for(ll i=2;(i*i)<=m;i++){
            if(m%i==0){
                ll cnt=0;
                while(m%i==0){
                    cnt++;
                    m=m/i;
                }
                vec.push_back({cnt,i});
                pro*=i;
                if(cnt<mini)
                mini=cnt;
            }
        }
        if(m!=1){
            vec.push_back({1,m});
            
            mini=1;
        }
       sort(vec.begin(),vec.end());
       vector<int>d(vec.size()+1);
       d[vec.size()]=1;
       for(int i=vec.size()-1;i>=0;i--){
        d[i]=(d[i+1]*vec[i].second);
       }
       ll ans=0;
       for(int i=0;i<vec.size();i++){
        if(i==0){
            ans=ans+d[0]*(vec[0].first);
        }
        else{
            ans=ans+d[i]*(vec[i].first-vec[i-1].first);
        }
       }

       cout<<ans<<"\n";

    }
}