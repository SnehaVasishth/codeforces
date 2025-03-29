#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
      if(n==6){
        cout<<"1 1 2 3 1 2\n";
      }
      else{
        for(int i=1;i<=(n-2);i++){
            cout<<i<<" ";
        }
        cout<<"1 2 \n";
      }
        
    }
}