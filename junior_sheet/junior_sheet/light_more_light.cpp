#include<bits/stdc++.h>

using namespace std;
int main(){
   long long int n;
   cin>>n;
   bool ans =0;
   for(int i=1;i<=n;i++){
    if(n%i==0){
        if(ans==0){
            ans=1;
        }
        else{
            ans=0;
        }
    }
   }
   if(ans==0 && n!=0){
    cout<<"no"<<"\n";
   }
   else if(ans==1 && n!=0){
    cout<<"yes"<<"\n";
   }
}