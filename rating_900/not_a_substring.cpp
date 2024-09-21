#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n= s.size();
        string a,b;
        for(int i=0;i<(2*n);i++){
            if(i%2==0){
                a+='(';
            }
             if(i%2!=0){
                a+=')';
            }
            if(i<n){
                b+='(';
               

            }
             if(i>=n){
                b+=')';
                
            }
        }
        if(a.find(s)==string::npos){
            cout<<"YES\n";
            cout<<a<<"\n";
        }
        else if(b.find(s)==string::npos){
            cout<<"YES\n";
            cout<<b<<"\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}