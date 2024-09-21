#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string>a(n);


        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        bool ans=1;
        string res="YES\n";

        if (a[0][0]!=a[n-1][m-1]){

            for(int i=0;i<=(m-2);i++){
                if((a[0][i]!=a[0][i+1]) || (a[n-1][i]!=a[n-1][i+1])){
                    ans=0;
                    break;
                }
            }
            if(ans==1){
                res="NO\n";

            }
            ans=1;
            
                for(int i=0;i<=(n-2);i++){
                    if((a[i][0]!=a[i+1][0])|| (a[i][m-1]!=a[i+1][m-1])){
                        ans=0;
                        break;
                    }
                }
                if(ans==1){
                    res="NO\n";
                }
            
        }
        cout<<res;

        
    }
}