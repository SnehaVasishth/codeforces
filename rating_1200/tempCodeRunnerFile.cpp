#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    ll mean,median;
    cin>>mean>>median;
    ll x,y;
    ll n=3;
    ll sum= 3*mean-median;
    if(mean<0){
        y= ((abs(median)-1)*-1);
        x= sum-y;
    }
    else{
        y= median+1;
        x=sum-y;

    }

    cout<<n<<"\n";
    cout<<x<<" "<<median<<" "<<y<<"\n";

}