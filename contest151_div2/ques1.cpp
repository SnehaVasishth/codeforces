#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,x;
        cin>>n>>k>>x;
        int m,l,p;
       if(k==x){
        cout<<"NO"<<"\n";
       }
       else{
        m= n/k;
        l=n%k;
        int size;
        if(l==0){
            size=m;
        }
        else if(l!=0){
            size=m+1;
        }
        if(l!=x){
            cout<<"YES"<<"\n";
            cout<<size<<"\n";
            for(int i=0;i<m;i++){
cout<<k<<" ";
            
            }
            
            if(l!=0)
            cout<<l<<"\n";
            else{
                cout<<"\n";
            }
        }
        else if(l==x){
            cout<<"NO"<<"\n";
        }
       }
    }
    
}