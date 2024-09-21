#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n%2!=0){
            for(int i=1;i<=n;i++){
                cout<<1<<" ";
            }
            cout<<"\n";
        }
        else if(n%2==0){
           cout<<1<<" "<<3<<" ";
           for(int i=1;i<=n-2;i++){
            cout<<2<<" ";

           }
            cout<<"\n";
        }
    }
}