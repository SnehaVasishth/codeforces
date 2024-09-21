#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
          ll ans1=0,ans2=0;
        vector<ll>a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            ans1+=a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            ans2+=b[i];
        }
      
        ll a_min= *min_element(a.begin(),a.end());
        ll b_min= *min_element(b.begin(),b.end());
        ll mini =min(a_min,b_min);
        ll res1=0,res2=0;
        res1=ans2+a_min*n;
        res2=ans1+b_min*n;
        ll res= min(res1,res2);
        cout<<res<<"\n";

    }
}