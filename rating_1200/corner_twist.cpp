#include<bits/stdc++.h>
#define ll long long
using namespace std;

void op(char &c,int k){
    c= ('0'+(((c-'0')+k)%3));
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string>a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
     
        for(int i=0;i<=n-2;i++){
            for(int j=0;j<=m-2;j++){
                while(a[i][j]!=b[i][j]){
                    op(a[i][j],1);
                    op(a[i+1][j+1],1);
                    op(a[i][j+1],2);
                    op(a[i+1][j],2);
                }
            }
        }
        if(a==b){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}