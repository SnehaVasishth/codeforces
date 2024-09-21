#include<bits/stdc++.h>
# define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<ll>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        ll l= a[0]-x;
        ll r= a[0]+x;
        int cnt=0;
        for(int i=1;i<n;i++){
            l= max(l,a[i]-x);
            r= min(r,a[i]+x);
            if(l>r){
                cnt++;
                l=a[i]-x;
                r= a[i]+x;
            }

        }
        cout<<cnt<<"\n";
    }
}