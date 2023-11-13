#include<bits/stdc++.h>

using namespace std;
string solve(){
    int n,k;
    cin>>n>>k;
    vector<int>b(n);
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int start=0;
    k= min(n,k);
    for(int i=0;i<k;i++){
        int end= (start+n-1)%n;
        int val= b[end];
        if(val>n){
            return "NO\n";
        }
        else{
            start=(start-val+n)%n;
        }

    }
    return "YES\n";
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve();
    }
}