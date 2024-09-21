#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>a(n),b(m);
        ll A=0;

        for(ll i=0;i<n;i++){
            cin>>a[i];
            A=(a[i]^A);
        }
        ll B=0;

        for(ll i=0;i<m;i++){
            cin>>b[i];
            B=(B|b[i]);
            
        }
        ll A1=0;
        for(ll i=0;i<n;i++){
            A1=A1^(a[i]|B);
        }
        if((n&1)==0){
            cout<<A1<<" "<<A<<"\n";
        }
        else{
            cout<<A<<" "<<A1<<"\n";
        }

    }
}