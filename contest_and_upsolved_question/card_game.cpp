#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a1,a2,b1,b2;
        cin>>a1>>a2>>b1>>b2;
    //   int  mini_a= min(a1,a2);
    //   int  maxi_a=max(a1,a2);
    //   int  maxi_b=max(b1,b2);
    //   int  mini_b=min(b1,b2);
    //     int cnt=0;
    //     if(mini_a>mini_b){
    //         cnt++;
    //         if(maxi_a>maxi_b){
    //             cnt++;
    //         }
    //         if(mini_a>maxi_b){
    //             cnt++;
            
    //         if(maxi_a>mini_b){
    //                 cnt++;
    //         }
    //         }
    //     }
    //     else if(mini_a<mini_b){
    //         if(maxi_a>mini_b){
    //             cnt++;
    //         }
    //     }


int cnt=0;
    if(a1>b1 && a1>b2 && a2>b1 && a2>b2){
        cnt=4;
    }
   
    else if((a1>b1 && a2>b2) || (a1>b2 && a2>b1)){
        cnt=2;
    }
        cout<<cnt<<"\n";
    }
}