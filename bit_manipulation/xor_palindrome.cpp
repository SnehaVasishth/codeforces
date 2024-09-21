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
        vector<int>t(n+1,0);
        int diff=0,same=0;
        for(int i=0;i<n/2;i++){
            if(s[i]==s[n-1-i]){
                same++;
            }
            else{
                diff++;
            }
        }
        cout<<same<<" "<<diff<<"\n";
        for(int i=0;i<=same;i++){
            int cnt= (i*2)+diff;
            // cout<<cnt<<"\n";
            t[cnt]=1;
            if(n&1){
                t[cnt+1]=1;
                // cout<<"tu kyu\n";
            }
        }
        for(auto it:t){
            cout<<it;
        }
        cout<<"\n";
    }
}