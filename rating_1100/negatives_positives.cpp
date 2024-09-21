#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll sum=0,res=0,maxi=0,neg=0,ab=0,small=INT_MAX;
        vector<ll>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
            ab+= abs(a[i]);
            if(a[i]<0){
                neg++;
            }
            if(abs(a[i])<small){
                small=abs(a[i]);
            }
        }
        if(neg&1){
            res= ab-2*small;
        }
        else{
            res=ab;
        }
        cout<<res<<"\n";
        
        }
        
    
}