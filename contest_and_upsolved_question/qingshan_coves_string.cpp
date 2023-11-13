#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>s(n);
        vector<int>t(m);
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        for(int i=0;i<m;i++){
            cin>>t[i];
        }

        bool flag=0;
        for(int i=1;i<m;i++){
            if(t[i]==t[i-1]){
                flag=1;
                break;
            }
        }
int allgood=3;
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                if(t[0]!=s[i-1] && t[m-1]!=s[i] && flag==0){
                    allgood=2;
                    cout<<"sneha\n";
                    
                }
                else{
                    allgood=1;
                    cout<<"aashi\n";
                    break;
                }
            }
        }
        if(allgood==3 && flag==1){
            cout<<"YES vasishth\n";
        }
        else if(allgood==3 || allgood==2){
            cout<<"YES sharama\n";
        }
        else if(allgood==1 || flag==1){
            cout<<"NO kuch bhi\n";
        }
    }
    
}