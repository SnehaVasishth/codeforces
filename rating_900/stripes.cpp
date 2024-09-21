#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        bool flag=0;
        vector<vector<char>>v(8,vector<char>(8));
        for(int i=0;i<=7;i++){
            int cnt=0;
            for(int j=0;j<=7;j++){
                char c;
                cin>>c;
                v[i][j]=c;
                if(c=='R'){
                    cnt++;
                }
                
            }
            if(cnt==8){
               
                flag=1;
               
            }
        }
        if(flag==1){
            cout<<"R\n";
        }
        if(flag==0){
           
                    cout<<"B\n";
                }
            
        }
    
}