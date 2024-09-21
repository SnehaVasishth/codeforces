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
        int ans=0;

        for(int i=0;i<n;i++){
            if(s[i]=='-'){
                ans=ans-1;

            }
            if(s[i]=='+'){
                ans=ans+1;
            }
        }
        cout<<abs(ans)<<"\n";
    }
}