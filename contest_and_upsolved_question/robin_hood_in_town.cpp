#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>a(n);
        ll sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(n==1 || n==2){
            cout<<-1<<"\n";
        }
        else{
        sort(a.begin(),a.end());
        ll half= (n/2);
        ll nth= a[half];
        ll wealth= (nth * n*2)+1;
        ll ans= wealth-sum;
        if(ans<0){
            ans=0;
        }
        cout<<ans<<"\n";
        }

    }
}