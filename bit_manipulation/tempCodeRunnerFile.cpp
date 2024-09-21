#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll>a(2*n);
        vector<ll>a1,a2,v;
        unordered_map<ll,ll>mp;
        for(int i=0;i<2*n;i++){
            cin>>a[i];
            if(i<n){
                mp[a[i]]++;
            }
          
        }
        
        for(int i=1;i<=n;i++){
            if(mp.find(i)==mp.end()){
                mp[i]=0;
                v.push_back(i);

            }
        }
        
        ll m=2*k;

        for(auto it:mp){
            if(m){
                if(it.second==2){
                    a1.push_back(it.first);
                    a1.push_back(it.first);
                    a2.push_back(v.back());
                    a2.push_back(v.back());
                    v.pop_back();
                    m-=2;
                }
                else if(it.second==1){
                    a1.push_back(it.first);
                    a2.push_back(it.first);
                    m--;
                }
            }
            else{
                break;
            }
        }
        for(int i=0;i<2*k;i++){
            cout<<a1[i]<<" ";
        }
        cout<<"\n";
        for(int i=0;i<2*k;i++){
            cout<<a2[i]<<" ";
        }
        cout<<"\n";
        
    }
}