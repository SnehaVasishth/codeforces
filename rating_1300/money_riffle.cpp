#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
int n;
cin>>n;
vector<int>a(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
int i=0,j=n-1;
ll cnt=0;

while(i<j){
    if(a[i]<a[j]){
        cnt+=a[j];
        // cout<<"valye sneha:"<<a[j]<<"\n";
        // cout<<"j: sneha "<<j<<"\n";
        j--;
        if(a[i]<a[j]){
            j--;
            // cout<<"j ashi "<<j<<"\n";
        }
        else if(a[i]>a[j]){
            i++;
            // cout<<"i  ashi "<<i<<"\n";
        }
    }
    else if(a[i]>a[j]){
        cnt+=a[i];
        // cout<<"kya  va;ue "<<a[i]<<"\n";
        // cout<<"kya i "<<i<<"\n";
        i++;
        if(a[i]>a[j]){
            i++;
            // cout<<"isnide i "<<i<<"\n";
        }
        else if(a[i]<a[j]){
            j--;
            //  cout<<"isnide j "<<j<<"\n";
        }
        }
    }


cout<<cnt<<"\n";
    }
}