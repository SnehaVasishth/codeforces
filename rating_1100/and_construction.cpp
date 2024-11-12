#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n),b(n-1);
        for(int i=0;i<n-1;i++){
            cin>>b[i];
        }
        a[0]=b[0];
        for(int i=1;i<n;i++){
            int third=0;
            for(int j=0;j<=31;j++){
                int bit1= ((a[i-1]>>j)&1);
                int bit2= ((b[i-1]>>j)&1);
                // cout<<bit1<<" "<<bit2<<"\n";
                if(bit2==1){
                    third=(third|(1<<j));
                    if(bit1==0){
                        a[i-1]=(a[i-1]|(1<<j));
                    }
                }
            }
            a[i]=third;
        }
        bool flag=0;
        // for(int i=0;i<n;i++){
        //         cout<<a[i]<<" ";
        //     }
        //     cout<<"\n";
        for(int i=0;i<=(n-2);i++){
            if((a[i]&a[i+1])!=b[i]){
                flag=1;
                break;
            }
        }
        if(flag==1){
            cout<<-1<<"\n";
        }
        else{
            for(int i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }
    }
}
