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
        int i=0;
        int j=0;
        for(int k=0;k<s.size();k++){
            if(s[k]=='U')
            j++;
            if(s[k]=='D')
            j--;
            if(s[k]=='R')
            i++;
            if(s[k]=='L')
            i--;
            if(i==1 && j==1)
            {
                cout<<"YES\n";
                flag=1;
                break;
            }

        }
        if(flag==0)
        cout<<"NO\n";
    }
}