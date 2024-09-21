#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    bool flag=0;
    for(int i=0;i<=(n-4);i++){
        string m="";
        m+=s[i];
        m+=s[i+1];
       
        if((s.find(m,i+2)!=string::npos)){
            flag=1;
           
            break;
        }

    }
    if(flag==1){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }
    }
}