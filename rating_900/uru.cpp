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
        int cnt=0;
        for(int i=1;i<n;i++){
            if(s[i]=='0' && s[i-1]=='1'){
                flag=1;
                cnt++;
                s[i]='1';
            }
            
        }
    }
}