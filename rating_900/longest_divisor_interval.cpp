#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==1 || n==2){
            cout<<n<<"\n";
        }
        else{
       for(int i=1;i<=n;i++){
        if(n%i!=0){
            cout<<i-1<<"\n";
            break;
        }
       }
        }

    }
}