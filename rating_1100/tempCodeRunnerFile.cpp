#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<ll>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        ll sum= accumulate(a.begin(),a.end(),0);
        int i=0;
        int j=n-1;

        while(k!=0){
            if(a[i]+a[i+1]<=a[j]){
                sum=sum -(a[i]+a[i+1]);
                i=i+2;
            }
            else if(a[j]< (a[i]+a[i+1])){
                sum= sum- a[j];
                j--;
            }
            k--;
        }

        cout<<sum<<"\n";

    }
}