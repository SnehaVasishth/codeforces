#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
       string v;
       cin>>v;
       if(v[0]=='?'){
        v[0]='0';
       } 

       for(int i=1;i<v.size();i++){
        if(v[i]=='?' && v[i-1]=='0'){
            v[i]='0';
        }
        else if(v[i]=='?' && v[i-1]=='1'){
            v[i]='1';
        }
       }
       cout<<v<<"\n";
    }
}