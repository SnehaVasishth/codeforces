#include<bits/stdc++.h>
#define ll long long
#define ld  double
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
ll px,py,ax,ay,bx,by;
cin>>px>>py>>ax>>ay>>bx>>by;
ld disoa= sqrt((ld)((ax*ax)+(ay*ay)));
ld disob= sqrt((ld)((bx*bx)+(by*by)));
ld dispa= sqrt((ld)(((px-ax)*(px-ax))+((py-ay)*(py-ay))));
ld dispb= sqrt((ld)(((px-bx)*(px-bx))+((py-by)*(py-by))));
ld disba= ((ld)sqrt((ld)(((bx-ax)*(bx-ax))+((by-ay)*(by-ay)))))/2;

ld mini1= max(disoa,dispa);
ld mini2= max(disob,dispb);
ld mini3= max(disoa,max(dispb,disba));
ld mini4= max(disob,max(dispa,disba));
ld res= min(mini1,min(mini2,min(mini3,mini4)));
cout<<setprecision(10)<<res<<"\n";


}
}