#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        int first_large=0,second_large=-1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i!=(n-1) && a[i]>second_large){
                second_large=a[i];
            }
        }
        first_large=a[n-1];
        if(second_large+1 != first_large)
        cout<<"Ambiguous\n";
        else{
            cout<<second_large<<"\n";
        }
    }
}