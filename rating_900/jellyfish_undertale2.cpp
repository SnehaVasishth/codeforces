#include<bits/stdc++.h>
#define ll long long int

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
       ll a,b,n;
        cin>>a>>b>>n;
        ll second=b;
        for(int i=0;i<n;i++){
           ll  x;
            cin>>x;
            x= min(x+1,a);
            x--;
            second+=x;

        }
        cout<<second<<"\n";
    }
}