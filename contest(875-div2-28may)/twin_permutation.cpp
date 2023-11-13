#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int>a(n);
        vector<int>b(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[i]=x;
            b[i]=(n+1)-a[i];
        }
        for(auto i:b){
            cout<<i<<"\n";
        }
    }
    
}