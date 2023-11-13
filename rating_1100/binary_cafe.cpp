#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
      long long  int n,k;
        cin>>n>>k;
        long long m=n+1;
        long long int a= ceil(log2(m));
        if(a>k){
        //    std::fixed;
        //    cout<<pow(2,k)<<"\n";
        long long int b= pow(2,k);
        std::cout<<fixed;
        cout<<b<<"\n";

        }
        else{
            cout<<m<<"\n";
        }
   
    }
    
}