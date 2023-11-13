#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int pro=1;
        int n= s.size();
        for(int i= n-1;i>=0;i--){
            char a= s[i];
            if(a=='?'){
                if(i==0){
                    pro= pro*9;
                }
                else{
                    pro= pro*10;
                }
            }
        }
        if(s[0]=='0')
        cout<<0<<"\n";
        else{
            cout<<pro<<"\n";
        }
    }
}