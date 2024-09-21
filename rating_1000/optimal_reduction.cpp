#include<bits/stdc++.h>

using namespace std;
bool solve(vector<int>&a){
    int n=a.size();
    int flag=0;
    int last=0;
   for(int i=1;i<=n-2;i++){
    if(a[i]<a[i-1] && a[i]<a[i+1]){
        return 0;
    }
    else if(a[i]<a[i-1] && a[i]==a[i+1]){
        last=a[i-1];
    }
    else if(a[i]==a[i-1] && a[i]<a[i+1]){
        if(last>a[i]){
            return 0;
        }

    }
   }
   return 1;
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
        bool ans =solve(a);
        ans==true?cout<<"YES\n":cout<<"NO\n";
    }
}