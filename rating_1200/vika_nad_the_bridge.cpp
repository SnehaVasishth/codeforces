#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool solve(ll step,vector<ll>&a,ll n){
    ll i=0;
    ll num=a[i+step];
    i=i+step+1;
    // cout<<"i: "<<i<<"\n";
    // cout<<"bool step"<<step<<"\n";
    bool flag=0;

    for(ll j=i+step; j<n;j++){

        ll k=a[j];
        // cout<<"loo[ p] ka j "<<j<<"\n";
        // cout<<"value k: "<<k<<"\n";
        if(k!=num && flag==0){
            flag=1;
          
        //  cout<<"sneha \n";
        }
        else if(k!=num && flag==1){
            // cout<<"aashhi \n";
            return false;
        }
        j+=step;
        // cout<<"badha diya:"<<j<<"\n";
    }
    return true;
}
int main(){

    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        ll i=0,j=n-1;

        while(i<=j){
            ll mid= (i+j)/2 ;
            // cout<<"step: "<<mid<<"\n";
            bool ans= solve(mid,a,n);
            
            if(ans==true){
                j=mid-1;
                // cout<<"j  main:"<<j<<"\n";
            }
            else if(ans==false){
                i=mid+1;
                // cout<<"i main:"<<i<<"\n";
            }

        }

        cout<<i<<"\n";
    }
}