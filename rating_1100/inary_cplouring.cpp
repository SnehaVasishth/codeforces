#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        int n;
        vector<ll>a(32,0);
        bool flag=0;
        int cnt=0;
        while(x>0){
            ll curr=0;
            while(x>=(1<<(curr+1))){
                curr++;
                if(flag==0){
                    flag=1;
                }
            }
            cnt++;

            if(cnt==1){
                n=curr;
                
            }
            a[curr]=1;
            x=(x%(1<<curr));
            

        }
        cout<<(31)<<"\n";
        for(int i=0;i<=29;i++){
            if(a[i]==1 && a[i+1]==1){
                a[i]=-1;
                a[i+1]=0;
                a[i+2]=1;
            }
           
        }
        for(int i=0;i<=31;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}