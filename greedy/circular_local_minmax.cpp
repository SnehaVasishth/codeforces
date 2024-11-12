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
        if(n%2==1)
        cout<<"NO\n";
        else{
        sort(a.begin(),a.end());
        int i=0,j=n/2,k=0;
        vector<ll>b(n);
        while(i<n/2 && j<n){
            b[k]=a[i];
            k++;
            i++;
            b[k]=a[j];
            k++;
            j++;

        }
        // for(int i=0;i<n;i++){
        //     cout<<b[i]<<" ";
        // }
        cout<<"\n";
        bool flag=0;
        for(int i=0;i<n;i++)
        {
            if(i==0){
                if((b[n-1]<b[0] && b[0]>b[1]) || (b[n-1]>b[0] && (b[1]>b[0]))){
                    continue;
                }
                else{
                    flag=1;
                    break;
                }
            }
            else if(i==n-1){
                if((b[n-2]<b[n-1] && b[n-1]>b[0]) || (b[n-2]>b[n-1] && (b[0]>b[n-1]))){
                    continue;
                }
                else{
                    flag=1;
                    break;
                }
            }
            else{
                if((b[i-1]<b[i] && b[i]>b[i+1]) || (b[i-1]>b[i] && (b[i+1]>b[i]))){
                    continue;
                }
                else{
                    flag=1;
                    break;
                }
            }
        }
        if(flag==1){
            cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
            for(int i=0;i<n;i++){
                cout<<b[i]<<" ";
            }
            cout<<"\n";
        }
        }
    }
}