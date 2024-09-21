#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll m;
        m=(n*(n-1))/2;


        vector<int>b(m);

        map<int,int>mp;
        vector<int>a(n);
int maxi=0;
        for(int i=0;i<m;i++){
            cin>>b[i];
            if(b[i]>maxi){
                maxi=b[i];
            }
            mp[b[i]]++;

        }
        int idx=n-1;
        for(auto it:mp){
             if(it.second>=n && mp.size()==1){
                for(int i=0;i<n;i++){
                    a[i]=it.first;
                }
                break;
            }
           else if((it.second==(idx)) && idx>=0){
                a[idx]=it.first;
                idx--;
            }
            else if(it.second!=idx && idx>=0){
               a[idx]=it.first;
               idx--;
               a[idx]=it.first;
               idx--;
            }
            
        }
        if(n==2){
            a[0]=b[0];
        }
        else if(n>2 ){
            a[0]=maxi+1;
        }

        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";

    }
}