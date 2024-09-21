#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,n;
        cin>>a>>b>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
       
        int second=0;
        int x=b;
        for(int i=0;i<n;){
            second++;
            
            if(x!=1){
                x--;
                continue;
            }
            
            x=min(x+v[i],a);
            x--;
           
            i++;
           
        }
        second= x+second;
        cout<<second<<"\n";
    }
}