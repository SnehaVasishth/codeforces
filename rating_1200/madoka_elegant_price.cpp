#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
    int n,m;
    cin>>n>>m;
    vector<string>v(n);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v[i]=s;
    }

    bool flag=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<m-1;j++){
            int a= v[i][j]+v[i][j+1]+v[i+1][j]+v[i+1][j+1]- 4*48;
            if(a==3){
                flag=1;
                break;
            }
        }
    }
    if(flag==1){
        cout<<"NO\n";
    }
    else{
        cout<<"YES\n";
    }
}
}