#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>a(n),b(m);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<m;i++){
            cin>>b[i];
        }

        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end());
        ll ans=0;
        bool flag=0;
        int idx=0;
        int idx1=m-1;
        int idx2=n-1;
        for(auto it:a){
            cout<<it<<" ";
        }
        cout<<"\n";
        for(auto it:b){
            cout<<it<<" ";
        }
        cout<<"\n";

    while(n && idx<=(m-1) && idx1>=0 && idx2>=0){

        if(flag==0){
            ans+=abs(a[idx]-b[idx]);
            flag=1;
            idx++;
            cout<<"ans "<<ans<<"\n";
        }
        else if(flag==1){
            ans+=abs(a[idx2]-b[idx1]);
            flag=0;
            idx1--;
            idx2--;
            cout<<"ans "<<ans<<"\n";
        }

        n--;
        

    }
    cout<<ans<<"\n";
    }
}