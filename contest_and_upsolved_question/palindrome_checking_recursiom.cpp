#include<bits/stdc++.h>
using namespace std;

bool check(string &s,int start,int end){
    if(start>=end){
        return true;
    }
    if(s[start]!=s[end])
    return false;
    bool a= check(s,start+1,end-1);
    if(a==false)
    return false;
    if(a==true && (s[start]==s[end]))
    return true;
}
int main(){
    string s;
    cin>>s;
    int  n=s.size();
    cout<<check(s,0,n-1);
}