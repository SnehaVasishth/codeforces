#include<bits/stdc++.h>

using namespace std;
int main(){
    
    vector<int>a(4);
    for(int i=0;i<4;i++){
        cin>>a[i];
    }
    string s;
    cin>>s;
    int res=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            res+=a[0];
        }
        if(s[i]=='2'){
            res+=a[1];
        }
        if(s[i]=='3'){
            res+=a[2];
        }
        if(s[i]=='4'){
            res+=a[3];
        }
    }
    cout<<res<<"\n";
}