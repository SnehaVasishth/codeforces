#include<bits/stdc++.h>

using namespace std;
void solve(vector<int>&a,int n){
    
    for(int i=1;i<n;i++){
        if(a[i]>a[i+1]){
            int x= log2(i);
            if(i!=pow(2,x)){
            cout<<"NO";
            return;

            }

        }
    }
    cout<<"YES";
   
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }

       solve(a,n);
       cout<<"\n";
    }

}