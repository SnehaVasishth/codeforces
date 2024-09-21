#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
            ll n;
            cin>>n;
            ll m=n;
            ll sum=0;
            while(m>0){
                int rem=m%10;
                sum+=rem;
                m=m/10;

            }
            cout<<sum<<"\n";
    }
}