#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        vector<pair<int,int>>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i].first;
            cin>>a[i].second;
        }
        int lb=INT_MIN;
        int ub=INT_MAX;

        for(int i=0;i<n;i++){
            if(a[i].first==1){
                lb=max(lb,a[i].second);
            }
            else if(a[i].first==2){
                ub=min(ub,a[i].second);
               
            }
        }
        
        ll ans= (ub-lb)+1;
        ans= (ans<=0)?0:ans;

        for(int i=0;i<n;i++){
            if(a[i].first==3){
                if(a[i].second>=lb && a[i].second<=ub){
                    ans--;
                }

            }
        }
        cout<<ans<<"\n";




    }
}