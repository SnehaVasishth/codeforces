#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,l,r;
        cin>>n>>l>>r;
        vector<int>ans(n);
       bool flag=0;
        for(int i=0;i<n;i++){
            ll num= r%(i+1);
            ll res= r-num;
            if(res>=l){
                ans[i]=res;
            }
            else{
                    flag=1;
                    break;
            }
        }

        if(flag==1){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            for(int i=0;i<n;i++){
                cout<<ans[i]<<" ";
            }
            cout<<"\n";
        }
    }
}