#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>b(n);
        vector<int>a(n);

        if(n==1){
            cout<<1<<"\n";
        }
        else if((n&1)!=0){
            cout<<-1<<"\n";
        }
        else if((n&1)==0){
            a[0]=n;
            b[0]=0;
            int k=1;
            ll sum=n;
            
    int i=1;
            for( i=1;i<n;i++){
                if((i&1)!=0){
                    b[i]=n-k;
                }
                else if((i&1)==0){
                    b[i]=k;
                    k++;
                }
                ll naya=sum/n;
            ll el1= b[i]+((naya+1)*n-sum);
            ll el2= b[i]-(sum%n);
            if(el1>=1 && el1<=n){
                a[i]=el1;
                sum+=a[i];
            }
            else if(el2>=1 && el2<=n){
                a[i]=el2;
                sum+=a[i];
            }
            }

            for(int i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<"\n";
            
        }
    }
}