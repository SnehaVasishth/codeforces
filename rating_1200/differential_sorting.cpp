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
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        bool flag=0;
        for(int i=1;i<n;i++){
            if(a[i]<a[i-1])
            {
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<0<<"\n";
        }
        else if(a[n-2]>a[n-1])
        cout<<-1<<"\n";
        else{
            if(a[n-1]<0){
                cout<<-1<<"\n";
            }
            else{
            cout<<n-2<<"\n";
            for(int i=0;i<=n-3;i++){
                cout<<i+1<<" "<<n-1<<" "<<n<<"\n";
            }
            }
        }
    }
}