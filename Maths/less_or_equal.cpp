#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&v,int n,int k){
    sort(v.begin(),v.end());
    if(k==0 && v[0]>1)
    return 1;   
    if((k==0 && v[0]==1) || (k<=(n-1) && v[k]==v[k-1]))
    return -1;
    return v[k-1];

}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>v(n);
    for(int i=0;i<n;i++)
    cin>>v[i];

  int ans=  solve(v,n,k);
  cout<<ans<<"\n";

}
