#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>ans(n),a(n),prefix(n);
        ll odd=0,sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            // if(i==0)
            // prefix[0]=a[0];
            // sum+=a[i];


        }
        for(int i=0;i<n;i++){
            sum+=a[i];
            if(a[i]&1){
                odd++;
            }
            if(i==0){
                ans[i]=a[i];
            }
           else if(odd%3==1){
                ans[i]=sum-(odd/3)-1;
            }
            else{
                ans[i]=sum-(odd/3);
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}