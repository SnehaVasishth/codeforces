#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        vector<int>a(n),b(m);
        multiset<int>s;
        for(int i=0;i<n;i++)
        cin>>a[i];

        for(int i=0;i<m;i++){
            cin>>b[i];
            s.insert(b[i]);
        }

        int i=0,j=0,len=0,ans=0;

        while(j<n){

            while((j-i+1)>m){
                if(s.find(a[j])!=s.end()){
                    len++;
                }
                j++;
            }
            if(len>=k){
                ans++;
            }
            if(s.find(a[i])!=s.end()){
                
            }
        }
    }
}