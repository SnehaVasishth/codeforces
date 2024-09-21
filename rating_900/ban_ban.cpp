#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n==1){
            cout<<1<<"\n";
            cout<<1<<" "<<2<<"\n";
        }
        else if(n>1){
            if(n%2!=0){
                cout<<((n/2)+1)<<"\n";
            }
            else{
                cout<<(n/2)<<"\n";
            }
            int i=2,j=6;
            for(int k=1;k<=n/2;k++){
                cout<<i<<" "<<j<<"\n";
                i+=6;
                j+=6;

            }
            if(n%2!=0){
                j-=6;
                cout<<j+1<<" "<<j+2<<"\n";

            }
        }
    }
}