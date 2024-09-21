#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(ll x,ll y,ll k){
    x++;
    k--;
    while(x!=y){
            while(x%y==0){
                x=x/y;
            }
            if(k==0){
                cout<<x<<"\n";
                return;
            }
            ll left= y-(x%y);
            if(left<=k){
                x=x+left;
                k=k-left;

            }
            else{
                cout<<x+k<<"\n";
                return;
            }
    }
    cout<<(1+k%(y-1))<<"\n";
    return;
}
int main(){
    int t;
    cin>>t;
    while(t--){
    ll x,y,k;
    cin>>x>>y>>k;
    solve(x,y,k);
    }
}