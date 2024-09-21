#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
      ll n;
        cin>>n;
        ll x= log(n)/log(2);
        ll y= pow(2,x);
        cout<<y<<"\n";
    }
}