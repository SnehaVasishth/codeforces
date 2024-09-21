#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool check(ll extra,ll n,ll my_curr_sum ,ll fr_curr_sum,vector<ll>&a,vector<ll>&b){
    ll size=n+extra;
    ll contest=size-size/4;
    ll my_sum=my_curr_sum,fr_sum=fr_curr_sum;
   

    ll i= (n-n/4)-1;
    ll how=contest-(n-(n/4));
     my_sum+=(extra*100);
     how=how-extra;
    // cout<<" extra "<<extra<<" "<<" size "<<size<<" "<<" contest need "<<contest<<" i "<<i<<" how "<<how<<"\n";
    while(how>0 && i>=0){
        my_sum-=a[i];
        i--;
        how--;
    }
    how=contest-(n-(n/4));
    ll j=(n-(n/4));
    while(how && j<n){
        fr_sum+=b[j];
        j++;
        how--;
    }
    // cout<<" y "<<my_sum<<" fr "<<fr_sum<<"\n";
    return (my_sum>=fr_sum)?true:false;

}

int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>a(n),b(n),pre_my(n),pre_fr(n);
        ll total_my_sum=0,total_frsum=0;
        
        for(ll i=0;i<n;i++){
        cin>>a[i];
        total_my_sum+=a[i];
        
        }

        for(ll i=0;i<n;i++){
        cin>>b[i];
        total_frsum+=b[i];
         
        }

        sort(a.begin(),a.end(),greater<ll>());
        sort(b.begin(),b.end(),greater<ll>());
        for(int i=0;i<n;i++){
            if(i==0){
                pre_my[0]=a[0];
                pre_fr[0]=b[0];
            }
            else{
                pre_my[i]=pre_my[i-1]+a[i];
                pre_fr[i]=pre_fr[i-1]+b[i];
            }
        }
        ll curr_test= n-n/4;
        ll my_curr_sum=pre_my[curr_test-1];
        ll fr_curr_sum=pre_fr[curr_test-1];
        // for(int i=0;i<n;i++){
        //     cout<<"a[i] "<<a[i]<<" "<<b[i]<<" "<<pre_my[i]<<" "<<pre_fr[i]<<"\n";
        // }
        // cout<<" my "<<my_curr_sum<<" "<<fr_curr_sum<<"\n";
        ll need= fr_curr_sum-my_curr_sum;
        ll i=0,j=n;
        while(i<=j){
            ll extra=(i+j)/2;
            if(check(extra,n,my_curr_sum,fr_curr_sum,a,b)){
                j=extra-1;
            }
            else{
                i=extra+1;
            }
        }
        cout<<i<<"\n";


    }
}