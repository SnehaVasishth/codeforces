#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>a(n),b(n-1);
        for(int i=0;i<n-1;i++){
            cin>>b[i];
        }
        if((n-1)==1){
            a[0]=b[0];
            a[1]=b[0];
        }
        else{
            int i;
            if(b[0]<b[1]){
                a[0]=b[0];
                a[1]=b[0];
                
                i=2;
            }
            else if(b[0]>b[1]){
                a[0]=b[0];
                a[1]=b[1];
               
                i=2;
            }
            else if(b[0]==b[1]){
                a[0]=b[0];
                a[1]=b[1];
                i=2;
            }
            for(i;i<(n);i++){
                if(a[i-1]<b[i-1])
                a[i]=b[i-1];
                else if(a[i-1]==b[i-1])
                {
                    // if((b[i-1]-1)>=0){
                    //     a[i]=(b[i-1]-1);
                    // }
                    // else{
                    //     a[i]=b[i-1];
                    // }
                    if(i<=(n-2))
                    a[i]= min(b[i-1],b[i]);
                    else if(i>(n-2))
                    a[i]=b[i-1];
                }
            }

        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }
}