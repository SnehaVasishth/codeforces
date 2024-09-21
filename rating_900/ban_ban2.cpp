#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%2!=0){
            cout<<((n/2)+1)<<"\n";
            cout<<1<<" "<<3<<"\n";
            ll i=5;
            ll j=3*n;
            for(int k=1;k<=(n/2);k++){
                cout<<i<<" "<<j<<"\n";
                i+=3;
                j-=3;
            }
        }
        else if(n%2==0){
            cout<<(n/2)<<"\n";
            ll i=2;
            ll j=3*n;
            for(int k=1;k<=(n/2);k++){
                cout<<i<<" "<<j<<"\n";
                i+=3;
                j-=3;

            }
        }
    }
}