#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    ll mean,median;
    cin>>mean>>median;
    ll x,y;
    ll n=3;
    ll one= 3*mean-2*median;
    ll two= median;
    if(one>=two){
        y=one;
        x=two;
    }
    else{
        x=one;
        y=two;
    }

   

    cout<<n<<"\n";
    cout<<x<<" "<<median<<" "<<y<<"\n";

}