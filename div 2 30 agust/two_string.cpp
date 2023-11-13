#include<bits/stdc++.h>

using namespace std;
string fun(string &a,string&b){
     string m=a;
    string n=b;
    string p=a;
    string q=b;
    int max_left=0;
    int max_right=INT_MAX;
    string ans;
    for(int i=0;i<a.size();i++){
        if(a[i]=='0' && b[i]=='0'){
            max_left=max(i,max_left);
        }
    }
    for(int k=0;k<max_left;k++){
        m[k]='0';
        n[k]='0';
    }
    if(m==n){
ans="YES";
cout<<"SNEHA"<<"\n";
cout<<m<<"  "<<n<<"\n";
return ans;
    }
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]=='1' &&b[i]=='1'){
            max_right=min(i,max_right);
        }
    }

    for(int k=a.size()-1;k>=max_right;k--){
        p[k]='1';
        q[k]='1';

    }
    if(p==q){
        ans="YES";
        cout<<"AASHI"<<"\n";
        cout<<p<<"  "<<q<<"\n";
        return ans;
    }
    for(int i=a.size()-1;i>=max_right;i--){
        m[i]='1';
        n[i]='1';
    }
    if(m==n){
        ans="YES";
        cout<<"Daksh"<<"\n";
        cout<<m<<"  "<<n<<"\n";
        return ans;
    }

    for(int i=1;i<max_left;i++){
        p[i]='0';
        q[i]='0';

    }
    if(p==q){
        ans="YES";
        cout<<"AAvi"<<"\n";
         cout<<p<<"  "<<q<<"\n";
        return ans;
    }
    ans="NO";
    return ans;

}
int main(){
    int t;
    cin>>t;
    while(t--){
    string a,b;
    cin>>a>>b;
   cout<<fun(a,b)<<"\n";


    }
    


}