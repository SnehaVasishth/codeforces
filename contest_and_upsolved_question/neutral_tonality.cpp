#include<bits/stdc++.h>

using namespace std;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
     for(int i=0;i<m;i++){
        cin>>b[i];
    }
    sort(b.begin(),b.end(),greater<int>());
    vector<int>c;
    int i=0,j=0;
    while(i<m && j<n){
        if(b[i]>=a[j]){
            c.push_back(b[i]);
            i++;
        }
        else if(a[j]>b[i]){
            c.push_back(a[j]);
            j++;
        }
    }
    while(i<m){
        c.push_back(b[i]);
        i++;
    }
    while(j<n){
        c.push_back(a[j]);
        j++;
    }
   for(auto i:c){
    cout<<i<<" ";
   }
   cout<<"\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
}