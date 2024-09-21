#include<bits/stdc++.h>
#define ll long long
using namespace std;

// ll power(ll n){

//     ll base=n;
//     ll po=n;
//     ll ans=1;
//     while(base>0){
//         if(base &1){
//             ans=ans*po;
//         }
//         po=po*po;
//         base=base>>1;
//     }
//     return ans;
// }

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll num=k;
        if((num%2)==0){
            ll half=(k)/2;
            if((half%2)==0){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            if((n%2)==0)
            {
                int odd= k/2;
                if((odd%2)!=0){
                    cout<<"NO\n";
                }
                else{
                    cout<<"YES\n";
                }
            }
            else if((n%2)!=0){
                int odd= ((k/2)+1);
                if((odd%2)==0){
                    cout<<"YES\n";
                }
                else{
                    cout<<"NO\n";
                }
            }
        }
        
    }
}