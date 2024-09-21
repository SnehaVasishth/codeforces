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
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

       int k=-1,l=-1;
        bool flag1=0,flag2=0;
int  d,e,i,j;
        for( i=0;i<=(n-2);i++){
            if(a[i]!=a[i+1] && i!=0){
                k=i+1;
                flag1=1;
                d=a[i];
                break;
            }
            else if(a[i]!=a[i+1] && i==0){
                k=i;
                flag1=1;
                break;
            }
           
        }
        for(j=(n-1);j>=1;j--){
            if(a[j]!=a[j-1] && (j!=(n-1))){
                l=j-1;
                flag2=1;
                e=a[j];
                break;
            }
            else if(a[j]!=a[j-1] && (j==(n-1))){
                l=j;
                flag2=1;
                break;
            }
        }
         cout<<"k "<<k<<" l "<<l<<"\n";
        if(flag1==1 && flag2==1){
            if(e!=d){
                int l1= (i+1);
                int l2= (n-1-j+1);
                if(l1<=l2){
                    k=0;
                }
                else{
                    l=n-1;
                }
            }
            if(e==d){
                if(i==0){
                    k++;
                }
                else if(j==n-1){
                    l--;
                }
            }
        }
        if(l==n-1 && k==0){
            if(a[l]==a[k]){
                k++;
                l--;
            }
            else {
                l--;
            }
        }
        if(k==-1 && l==-1){
            cout<<0<<"\n";
        }
        else{
        ll cost= (l-k+1);
        cout<<cost<<"\n";
        }
    }
}