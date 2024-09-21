#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<bool>arr(10000000+1,true);
void sieve(){
    arr[0]=false;
    arr[1]=false ;
    for(ll i=2;i<=1000000;i++){
        if(arr[i]==1){
            for(ll j=i*i;j<=10000000;j+=i){
                arr[j]=false;
            }
        }

    }
  
}
int main(){
    int n;
    cin>>n;
    ll sqt=0;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sieve();
    for(int i=0;i<n;i++){
         sqt=sqrt(a[i]);
        if((sqt*sqt)==a[i]){
            if(arr[sqt]==1){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
}