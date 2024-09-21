#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll sum1=0,sum2=0,maxi=-1;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum1+=a[i];
        }
         for(int i=0;i<n;i++){
            cin>>b[i];
            sum2+=b[i];
            if(b[i]>maxi){
                maxi=b[i];
            }

        }
        ll ans= sum1+sum2-maxi;
        cout<<ans<<"\n";

    }
}