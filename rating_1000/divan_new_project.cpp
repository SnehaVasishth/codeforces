#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<ll,ll>>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second=i;
        }
        sort(a.begin(),a.end(),greater<pair<ll,ll>>());

        ll hr=0;

        ll idx=-1, element=1;
        bool flag=0;
        vector<ll>ans(n+1);
        ans[0]=0;
        for(int i=0;i<n;i++){
            if(flag==0){
                ans[a[i].second+1]=idx;
                hr=abs(hr+ 2*abs(idx)*(a[i].first));
                element++;
                idx= idx+element;
                flag=1;
            }
            else if(flag==1){
                 ans[a[i].second+1]=idx;
                hr=abs(hr+ 2*abs(idx)*(a[i].first));
                element++;
                idx= idx-element;
                flag=0;
                
            }

        }
        cout<<hr<<"\n";
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
}