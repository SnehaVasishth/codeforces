#include<bits/stdc++.h>

using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        ll sum=0;
        vector<ll>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        sort(a.begin(),a.end());
        ll cnt=0;

        for(int i=0;i<n;i++){
            int k= lower_bound(a.begin(),a.end(),sum-y-a[i])-a.begin();
            int j=upper_bound(a.begin(),a.end(),sum-x-a[i])-a.begin();
            cnt+=(max(0,j-k));
            if(i>=k && i<j){
                cnt--;
            }
        }

        cout<<cnt/2<<"\n";
    }
}
