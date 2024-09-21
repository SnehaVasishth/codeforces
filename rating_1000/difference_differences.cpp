#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int k,n;
        cin>>k>>n;
        vector<int>a(41,0);
        int m=1;
        a[1]=1;
        for(int i=2;i<=9;i++){
            a[i]=a[i-1]+(i-1);      


        }
       int i=k;
         m=n;
        for(i;i>=1;i--){
            // cout<<a[i]<<" ";
            if(i<=9 &&(a[i]>n || a[i]>=a[i+1])){
                a[i]=m;
                // cout<<"value "<<m<<"\n";
                m--;


            }
           else if(i>9){
                a[i]=m;
                m--;
            }
            else{
                break;
            }
           
        }
        for(int i=1;i<=k;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";

    }

}