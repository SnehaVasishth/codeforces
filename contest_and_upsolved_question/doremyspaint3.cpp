#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map<int,int>s;
        for(int i=0;i<n;i++){
            int y;
            cin>>y;
            s[y]++;
        }
       

        int bata= s.size();
         auto it= s.begin();

        if(n%2!=0 && bata==2){

            int sneha= n/2 + n%2;

            int ashi= n -sneha;

            if(it->second == sneha){
                it++;
               
                if(it->second==ashi){
                    cout<<"YES\n";
                }
                
            }
            else if(it->second==ashi){
                it++;
               
                if(it->second==sneha){

                    cout<<"YES\n";
                }
                
            }
            else{
                cout<<"NO\n";
            }
                   }
        else if(n%2==0 && bata==2){

            int sneha= n/2;
            if(it->second ==sneha){

                it++;
              
                if(it->second==sneha){

                    cout<<"YES\n";
                }
                
            }
            else{
                cout<<"NO\n";
            }
        }
        else if(bata==1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}