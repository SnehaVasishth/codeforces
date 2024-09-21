#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        vector<ll>a(32,0);
        for(int i=31;i>=0;i--){
            if(x>=(1LL<<i)){
                a[i]=1;
               

            }
            x%=(1<<i);

        }
        int j=0;
        for(int i=0,j;i<32;){
            if(a[i]==0){
                i++;
                continue;
            }
            j=i+1;
            while(a[j]==1){
                a[j]=0;
                j++;
            }
            if(j>(i+1)){
                a[j]=1;
                a[i]=-1;
            }
            i=j;
        }
        cout<<32<<"\n";
        for(int i=0;i<32;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}