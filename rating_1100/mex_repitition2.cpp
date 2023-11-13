#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
      long long  int n,k;
        cin>>n>>k;
        long long int sum1= (n*(n+1))/2;
        long long int sum2=0;
        vector<int>v(n+1);
        for(int i=0;i<n;i++){
            cin>>v[i];
            sum2+=v[i];
        }
        v[n]=(sum1-sum2);
        k=k%(n+1);
        for(int i=0;i<n;i++){
            cout<<v[(n+1-k+i)%(n+1)]<<" ";
        }
        cout<<"\n";
    }
}