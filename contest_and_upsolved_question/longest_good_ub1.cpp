#include<bits/stdc++.h>

#define ll long long

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;

        ll num=0;
        ll diff=1;
        for(ll i=l;(i+diff)<=r;){
            num++;
            i=i+diff;
            diff++;
            
        }
        num++;
        cout<<num<<"\n";

    }
}