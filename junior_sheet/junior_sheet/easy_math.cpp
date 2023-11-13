#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n,m,a,d;
        cin>>n>>m>>a>>d;
        long long int cnt=0;
        for(int i=n;i<=m;i++){
            if((i%a)!=0 && (i%(a+d))!=0 &&(i%(a+2*d))!=0 && (i%(a+3*d))!=0 && (i%(a+4*d))!=0){
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }

}