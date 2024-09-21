#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>p(n),q(n);
        set<ll>st;
        vector<pair<ll,int>>v;
        int curr;
        for(int i=0;i<n;i++){
            cin>>p[i];
            st.insert(p[i]);
            if(p[i]==1){
                curr=i;
            }
        }

        for(int i=0;i<n;i++){
            if(curr%2!=i%2){
                q[i]=(n+2)-p[i];
                st.erase(q[i]);
            }
            else{
                v.push_back({p[i],i});
            }
        }
        auto comp=[](pair<ll,int>&a,pair<ll,int>&b){
            return a.first>b.first;
        };
        sort(v.begin(),v.end(),comp);
        int j=0;
        for(auto &it:st){
            q[v[j].second]=it;
            j++;
        }
        for(int i=0;i<n;i++){
            cout<<q[i]<<" ";
        }
        cout<<"\n";
    }
}
