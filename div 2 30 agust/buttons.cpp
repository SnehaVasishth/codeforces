#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        string ans;
        // if((a%2==0)&&(b%2==0)&&(c%2!=0)){
        //     ans="First";
        // }
        // if((a%2==0)&&(b%2==0)&&(c%2==0)){
        //     ans="Second";
        // }
        // if((a%2==0)&&(b%2!=0)&&(c%2!=0)){
        //     ans="Second";
        // }
        // if((a%2==0)&&(b%2!=0)&&(c%2==0)){
        //     ans="First";
        // }
        // if((a%2!=0)&&(b%2==0)&&(c%2!=0)){
        //     ans="Second";
        // }
        // if((a%2!=0)&&(b%2==0)&&(c%2==0)){
        //     ans="First";
        // }
        // if((a%2!=0)&&(b%2!=0)&&(c%2!=0)){
        //     ans="First";
        // }
        // if((a%2!=0)&&(b%2!=0)&&(c%2==0)){
        //     ans="Second";
        // }


        if(c%2==0){
            if(a>b){
                ans="First";
            }
            else if(b>a){
             ans="Second";
            }
            else if(a==b){
                ans="Second";
            }
        }
        else{
             if(a>b){
                ans="First";
            }
            else if(b>a){
             ans="Second";
            }
            else if(a==b){
                ans="First";
            }

        }

        cout<<ans<<"\n";

    }
}