#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve(vector<int>&a,int n){
    int fm=0;
    for(int i=0;i<n;i++){
        if(a[i]<a[fm]){
            fm=i;
        }
    }
    for(int i=fm+1;i<n;i++){
        if(a[i]<a[i-1]){
            cout<<-1<<"\n";
            return;
        }
    }
    cout<<fm<<"\n";
    return;
}

int main(){

int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    solve(a,n);
}
}