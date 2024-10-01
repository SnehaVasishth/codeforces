#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool perfectsqr(ll n){
    ll sqt= sqrt(n);
    return (sqt*sqt==n);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        ll k;
        cin>>k;
        ll n=1;
        ll cnt=0;
        while(cnt<k){
            if(perfectsqr(n)==false){
                cnt++;
            }
            n++;
        }
        n--;
        cout<<n<<"\n";
    }

}