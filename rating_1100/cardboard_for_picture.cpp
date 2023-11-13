#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll w;
        cin>>w;
        ll a=0,b=0,c=0;
        a= 4*n;
        for(int i=0;i<n;i++){
            ll x;
            cin>>x;
            c= (x*x)+c;
            b=  x*4+b;

        }
        c= c-w;
        cout<<a<<"  "<<b<<"  "<<c<<"\n";
        ll root1= (-b+sqrt(b*b - 4*a*c))/(2*a);
        ll root2= (-b - sqrt(b*b -4*a*c))/(2*a);
        if(root1>=0){
            cout<<root1<<"\n";
        }
        else{
            cout<<root2<<"\n";
        }
        
    }
}