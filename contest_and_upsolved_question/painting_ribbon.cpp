#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        ll bob_paint=0;
        int min_each_strip=n/m;
        int no_of_max_strip=n%m;
        int each_max_strip=min_each_strip+1;
        int no_of_min_strip=m-no_of_max_strip;
        if(no_of_max_strip!=0){
        bob_paint=(no_of_max_strip-1)*each_max_strip+(no_of_min_strip)*(min_each_strip);
        }
        else if(no_of_max_strip==0){
            bob_paint=(no_of_min_strip-1)*(min_each_strip);
        }
        if(bob_paint<=k){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
}