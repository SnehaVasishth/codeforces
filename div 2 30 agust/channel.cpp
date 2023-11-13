#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,q;
        cin>>n>>a>>q;
        string s;
        cin>>s;
        string ans;
        int p=0;
        int sub=0;
        int m=0;
        for(int i=0;i<q;i++){
            if(s[i]=='+'){
                p++;
            }
            else if(s[i]=='-'){
                sub++;
            }
        }
        m= p + sub*(-1);
        if(a==n ||((a+m)==n)){
            ans="YES";

        }
      else if((a+p)<n){
            ans="NO";
        }
       else if((a+m)<n){
            ans="MAYBE";
        }
        cout<<ans<<"\n";
        

    }
}