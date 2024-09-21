#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,c;
        cin>>n>>c;
        vector<ll>a(n),ans(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            ans[i]=(a[i]+i+1);
        }
        sort(ans.begin(),ans.end());
        ll res=0;
        for(int i=0;i<n;i++){
                if(ans[i]<=c){
                    res++;
                    c-=ans[i];
                }
                else{
                    break;
                }
        }
        cout<<res<<"\n";
    }
}