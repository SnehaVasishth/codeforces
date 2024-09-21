#include<bits/stdc++.h>

using namespace std;
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
       int b=a[0];
       int c=INT_MAX;
       
    int cnt=0;
        for(int i=1;i<n;i++){
           if(a[i]<min(b,c)){
            if(b<c){
                b=a[i];
            }
            else{
                c=a[i];
            }
           }
           else if(a[i]>max(b,c)){
            (b<c)?(b=a[i]):(c=a[i]);
            cnt++;
           }
           else if(a[i]>min(b,c) && a[i]<max(b,c)){
            (b>c)?(b=a[i]):(c=a[i]);
           }
          
        }
        cout<<cnt<<"\n";
    }
}