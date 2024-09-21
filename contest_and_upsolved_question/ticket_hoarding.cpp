#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++)
        cin>>a[i];
        sort(a.begin(),a.end());

        ll cost=0,fir=0;

        for(ll i =0;i<n;i++){
            if(k==0)
            break;
            if(m<=k){
                cost+=((a[i]+fir)*m);
                k=k-m;
            }
            else{
                cost+=((a[i]+fir)*k);
                k=0;
            }
            fir+=m;
            
        }
        cout<<cost<<"\n";
    }
}
