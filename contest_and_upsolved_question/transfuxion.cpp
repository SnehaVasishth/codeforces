#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>a(n);
        bool flag=0;
        ll sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%n==0)


        {
            ll num=sum/n;
            for(int i=1;i<=n-2;i++){
                int step= abs(num-a[i-1]);
                if(a[i-1]>num){
                    a[i-1]=num;
                    a[i+1]+=step;

                }
                else{
                    a[i-1]=num;
                    a[i+1]-=step;
                }
            }

            // for(int i=0;i<n;i++){
            //     cout<<a[i]<<" ";
            // }
            // cout<<"\n";
            
            for(int i=0;i<n;i++){
                if(a[i]!=num)
                {
                    flag=1;
                    break;
                }
            }

        }
        if((sum%n)!=0 || flag==1)
        cout<<"NO\n";
        else{
            cout<<"YES\n";
        }
    }
}