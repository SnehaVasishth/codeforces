#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n,k;
    cin>>n>>k;

    ll i=1,j=n;
    while(i<=j){
        ll mid= (i+j)/2;
        ll sum= ((mid*(mid+1))/2);
        ll diff= sum-k;
        ll total=diff+mid;
        if(total==n){
            cout<<diff<<"\n";
            break;
        }
        else if(total>n){
            j=mid-1;
        }
        else{
            i=mid+1;
        }
    }
}