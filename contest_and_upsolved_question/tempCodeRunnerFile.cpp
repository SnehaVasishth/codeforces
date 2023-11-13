#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
       long long int n,k,x;
        cin>>n>>k>>x;
        long long find=0;
        long long ans=0;
       long long int s=1;
      
      find= (k*(2*n+(k-1)*-1)/2);
      ans=(k*(2+(k-1))/2);
       
        if(find>=x && ans<=x){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
}