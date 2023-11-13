#include<bits/stdc++.h>

using namespace std;
int main(){
    int y,w;
    cin>>y>>w;
    int res= max(y,w);
    int a= 6-res+1;
    int b=6;
    int c= __gcd(a,b);
    a= a/c;
    b= b/c;
    cout<<a<<"/"<<b<<"\n";
}