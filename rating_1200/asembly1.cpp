#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll m= (n*(n-1))/2;
        vector<int>b(m);
       
        for(int i=0;i<m;i++){
            cin>>b[i];
          
        }
        sort(b.begin(),b.end());
        
        
        vector<int>a(n+1);
int idx=0;
       for(int i=1;i<n;i++){
        a[i]=b[idx];
        idx=(idx+(n-i));


       }
       a[n]=1e9+7;
       for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
       }
       cout<<"\n";

    }
}