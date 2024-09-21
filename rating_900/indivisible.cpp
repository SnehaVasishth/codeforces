#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        if(n%2!=0 && n!=1){
            cout<<-1<<"\n";
        }
       else if(n==1){
        cout<<1<<"\n";

        }
        else if(n%2==0){
            for(int i=0;i<n;i++){
                v[i]=n-i;
            }
            for(int i=1;i<n;i+=2){
                swap(v[i-1],v[i]);
            }
            for(int i=0;i<n;i++){
                cout<<v[i]<<" ";
            }
            cout<<"\n";
        }
    }
}
