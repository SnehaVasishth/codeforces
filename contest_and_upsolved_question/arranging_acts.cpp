#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s,f;
        cin>>s>>f;

        ll one=0,zero=0,oper=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1' && f[i]=='0'){
                one++;
                if((one>0 && zero==0) || (one==0 && zero>0)){
                oper++;
                
            }
            else{
                zero--;
                one--;
            }
            }
            if(s[i]=='0' && f[i]=='1'){
                zero++;
                if((one>0 && zero==0) || (one==0 && zero>0)){
                oper++;
               
            }
            else{
                zero--;
                one--;

            }
            }
            
        }
       
        cout<<oper<<"\n";

    }
}
