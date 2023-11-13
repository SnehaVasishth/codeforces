#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
       long long int n,k,x;
        cin>>n>>k>>x;
        long long aashi=0;

        long long kya=0;
      
      
      aashi= (k*(2*n+(k-1)*-1)/2);

      
      kya=(k*(2+(k-1))/2);
       
        if(aashi>=x && kya<=x){
            cout<<"YES"<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
}