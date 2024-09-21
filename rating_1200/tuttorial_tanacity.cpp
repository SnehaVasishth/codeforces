#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>a(n);
       for(int i=0;i<n;i++){
        cin>>a[i];
       }
       sort(a.begin(),a.end());
       if(a[0]!=a[1]){
        cout<<"YES\n";
       }else 
       {
        /* code */
        bool flag=0;
        for(int i=1;i<n;i++){
            if(a[i]%a[0]!=0){
                flag=1;
                break;
            }
        }
        if(flag==1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
       }
       
       

    }
}