#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>a(n);
        vector<int>b(m);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }

       
        int mini1=INT_MAX;


        int maxi1=INT_MIN;
        int first=0;
        for(int i=0;i<n;i++){
            first= first^a[i];
        }
        for(int i=0;i<m;i++){
             int sum=0;
            for(int j=0;j<n;j++){
                a[j]=a[j]|b[i];
                sum=sum^a[j];
        }
        if(sum<mini1){
            mini1=sum;
        }
        if(sum>maxi1){
            maxi1=sum;
        }
    }
    if(first>maxi1){
        maxi1=first;
    }
    if(first<mini1){
        mini1=first;
    }
    cout<<mini1<<" "<<maxi1<<"\n";
}
}