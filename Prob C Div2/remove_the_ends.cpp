#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>v(n);
        for(int i=0;i<n;i++)
        cin>>v[i];
        vector<ll>suffix(n+1);
        suffix[n]=0;
        for(int i=n-1;i>=0;i--){
            suffix[i]=abs(v[i])+suffix[i+1];
        }
        int i=0,j=n-1,l=0,r=n-1;
        ll pos=0,neg=0;
        ll sum=0;
        while(l<=r){
            while((i>=l && i<=r) && v[i]<0){
                i++;
               
            }
            while((j>=l && j<=r) && v[j]>0){
                j--;
                
            }
            cout<<"value of i "<<i<<"\n";
            cout<<"value of j "<<j<<"\n";
            if(i>=l && i<=r){
                pos= suffix[i]-suffix[r+1];
            }
            else{
                pos=0;
            }
            if((j>=l && j<=r)){
                neg= suffix[l]-suffix[j+1];
            }
            else{
                neg=0;
            }
            cout<<"value of pos "<<pos<<"\n";
            cout<<"value of neg "<<neg<<"\n";
            if(pos>=neg){
                sum+=(abs(v[i]));
                l=i+1;

            }
            else{
                sum+=(abs(v[j]));
                r=j-1;
            }
            i=l;
            j=r;
            cout<<"value of sum "<<sum<<"\n";
            cout<<"value of l "<<l<<"\n";
            cout<<"value of r "<<r<<"\n";
        }
        cout<<sum<<"\n";
    }
}