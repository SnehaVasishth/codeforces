#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    int ans=0;
    vector<int>a(n);
     for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n-1;i++){
            ans= a[i] ^ a[i+1];
        }
        for(int i=0;i<n;i++){
            a[i]=ans;
        }
        for(int i=0;i<n-1;i++){
            ans= a[i] ^ a[i+1];
        }
         for(int i=0;i<n;i++){
            a[i]=ans;
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<"  ";
        }
}