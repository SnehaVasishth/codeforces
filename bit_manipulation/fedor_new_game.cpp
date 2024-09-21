#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int>a(m+1);
    for(int i=0;i<=m;i++){
        cin>>a[i];
    }

    int x=0;
    ll cnt=0;
    for(int i=0;i<m;i++){
        x=(a[i]^a[m]);
        ll no=__builtin_popcount(x);
        if(no<=k){
            cnt++;
        }
    }
    cout<<cnt<<"\n";
}