#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,x;
        cin>>n>>k>>x;

        if(k>n){

            cout<<-1<<"\n";


        }
        else if(k>x && (k-1)>x){
           
                cout<<-1<<"\n";
            
        }
        else{

            long long int ans=0;


            int s=n;

            int y=0;
            
            while(y<k){
                
                    ans+=y;
                    s--;
                
                y++;
               
            }
            if(k!=x){
                y=x;
            }
            if(k==x){
                y--;
            }
           
            while(s){

                ans+=y;
                s--;
            }
            cout<<ans<<"\n";
        }
    }
}