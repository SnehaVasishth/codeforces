#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
   cin>>t;
   vector<string>a(t);
   for(int i=0;i<t;i++){
    string s;
    cin>>s;
    a[i]=s;
   }
   for(int i=0;i<t;i++){
    int n=a[i].size();
    if(n>10){
    int value= (a[i].size()-2);
    string v= to_string(value);
    string ans= a[i][0]+v+a[i][n-1];
    cout<<ans<<"\n";
    }
    else{
        cout<<a[i]<<"\n";
    }
    
   }
}