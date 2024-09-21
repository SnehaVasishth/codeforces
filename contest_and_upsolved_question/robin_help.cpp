#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        ll cnt=0;
        ll curr=0;
        for(int i=0;i<n;i++){
            if(a[i]>=k){
                curr+=a[i];
            }
            else if(a[i]==0 && curr>0){
                cnt++;
                curr--;
            }
        }
cout<<cnt<<"\n";

    }
}