#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll solve(vector<ll>&a){
    ll n=a.size();
    vector<ll>cal(n);
    ll res=0;
    cal[n-1]=0;
    for(ll i=n-2;i>=0;i--){
        cal[i]=cal[i+1]+((a[i+1]==0)?1:0);
        if(a[i]==1)
        res+=cal[i];
    }
    return res;
}
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>a(n);
        bool flag=0;
        ll first_zero=-1,last_one=-1;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            if(a[i]==0 && flag==0){
                first_zero=i;
                flag=1;
            }
            if(a[i]==1){
                last_one=i;
            }
        }

        ll maxi= solve(a);

        if(first_zero !=-1){
        a[first_zero]=1;
        maxi=max(maxi,solve(a));
        a[first_zero]=0;
        }
        if(last_one !=-1){
        a[last_one]=0;
        maxi=max(maxi,solve(a));
        a[last_one]=1;

        }

        cout<<maxi<<"\n";

    }
}