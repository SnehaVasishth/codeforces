#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n+1);
       

int mini=INT_MAX;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]<mini){
                mini=a[i];
            }


        }
        
        int idx=-1;

        for(int i=1;i<=n;i++){
            if(a[i]==mini){
                idx=i;
                break;
            }
        }
       

        if((n & 1)!=0){
           cout<<"Mike\n";
        }
        else{
            if((idx & 1)!=0){
                cout<<"Joe\n";
            }
            else{
                cout<<"Mike\n";
            }
        }
    }
}