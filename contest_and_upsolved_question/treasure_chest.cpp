#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,k;
        cin>>x>>y>>k;

        if(x>y){
            cout<<x<<"\n";

        }
        else if(x<y && k==0){
            cout<<(2*y-x)<<"\n";
        }
        else if((x+k)<y){
            int z= y-(x+k);
            int cost= x+k+2*z;
            cout<<cost<<"\n";
        }
        else if((x+k)>=y){
            cout<<y<<"\n";
        }
    }
}