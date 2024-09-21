#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>>a(n);
        vector<int>b(n);
        vector<int>c(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[i].first=x;
            a[i].second=i;

        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<n;i++){
            int idx= a[i].second;
            c[idx]=b[i];
        }
        for(auto id:c){
            cout<<id<<" ";
        }
        cout<<"\n";
    }
}