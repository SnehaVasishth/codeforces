#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int d;
    cin>>d;
    int i;
    for( i=0;i<s.size();i++){
        if(d<s[i])
        continue;
        else
        break;
    }
    int j=i;
    for(int k= s.size()-1;k>=i;k++){
        s[k+1]=s[k];
    }
    s[j]=d;
    cout<<s;
}