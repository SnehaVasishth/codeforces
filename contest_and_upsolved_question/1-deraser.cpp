#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;

        cin>>n>>k;
        int count=0;

        string a;
        cin>>a;
        for(int i=0;i<n;i++){
            if(a[i]=='B'){
                
                for(int j=i;j<k+i;j++){
                    
                    if(a[j]=='B'){
                        a[j]='W';
                    }
                }
                 count++;
            }
           
        }
        cout<<count<<"\n";
    }
    

}