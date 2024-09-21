#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    vector<ll>prefix(n),suffix(n);
    unordered_map<ll,int>mp1,mp2;
    prefix[0]=a[0];
    mp1[a[0]]=0;
    suffix[n-1]=a[n-1];
    mp2[a[n-1]]=n-1;
   
    for(int i=1;i<n;i++){
        prefix[i]=prefix[i-1]+a[i];
        mp1[prefix[i]]=i;
        suffix[n-1-i]=suffix[n-i]+a[n-1-i];
        mp2[suffix[n-1-i]]=n-1-i;
    }
    ll maxi=0;
    
    
    for(auto it:mp1){
        if(mp2.find(it.first)!=mp2.end()){
            if(mp2[it.first]>mp1[it.first]){
                maxi=max(maxi,it.first);
            }
           
        }
    }
    cout<<maxi<<"\n";
}