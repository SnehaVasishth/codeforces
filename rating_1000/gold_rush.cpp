#include<bits/stdc++.h>

using namespace std;

int fun(int n,int m){
   
    if(n==m){
       
        return 1;

    }
 if(n%3!=0){
    
        return 0;
    }
    if(n%3==0){    
       
               return  fun(n/3,m) +  fun((2*n)/3,m);
        
    }
   
   

}

int main(){
    int t;
    cin>>t;
    while(t--){
      
        int n,m;
        cin>>n>>m;
        long long int ans;
        ans= fun(n,m);
        if(ans>0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}