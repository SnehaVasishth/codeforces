#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;

        // ll cost1=2*a;
        // ll cost2=b;
        ll total=0;
        ll sale=0;
       
        sale=n/2;
            if(n%2==1){
                total=sale+1;
            }
            else
            total=sale;
        
        ll p1= sale*b+(total-sale)*a;
        ll p2= a*n;
       
        cout<<min(p1,p2)<<"\n";
    }
}