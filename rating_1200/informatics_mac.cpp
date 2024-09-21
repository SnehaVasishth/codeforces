#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>a(n);
        unordered_map<int,int>mp;
        for(int  i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]=1;
        }
        int mex=0;
        for(int i=0;i<=1e6;i++){
            if(mp[i]==0){
                mex=i;
                break;
            }
        }
        mp.clear();
        vector<pair<ll,ll>>ans;
        int left=0;
        for(int i=0;i<n;i++){
            if(a[i]<mex){
                mp[a[i]]=1;
            }
            if(mp.size()==mex){
                ans.push_back({left+1,i+1});
                left=i+1;
                mp.clear();

            }
            if(ans.size()==2){
                break;
            }
        }
        ans[ans.size()-1].second=n;
        if(mex==0){
            cout<<2<<"\n";
            cout<<1<<" "<<1<<"\n";
            cout<<2<<" "<<n<<"\n";
        }else{
            if(ans.size()<2){
                cout<<-1<<"\n";
            }
            else if(ans.size()==2){
                cout<<2<<"\n";
                cout<<ans[0].first<<" "<<ans[0].second<<"\n";
                cout<<ans[1].first<<" "<<ans[1].second<<"\n";
            }
        }
      }
    }
