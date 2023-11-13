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
        int k=0;
        int maxdiff=0;
        int maxsame=0;
        vector<int>sneha(n+1,0);
        if(n%2==1){
            k++;
        }
        for(int i=0;i<=(n/2)-1;i++){
            if(s[i]==s[n-i-1])
            maxsame++;
            else
            maxdiff++;
        }
        for(int i=0;i<=maxsame;i++){
            for(int j=0;j<=k;j++){
                sneha[maxdiff+i*2+j]=1;
            }
        }
        for(auto i:sneha){
            cout<<i; 
        }
        cout<<"\n";
    }
}