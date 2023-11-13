#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int mini1=INT_MAX;
    int mini2= INT_MAX;
    int max1=INT_MIN;
    int max2= INT_MIN;
    int mini;
    int maxi;
    for(int i=0;i<n;i++){
        if(i!=(n-1)){
            mini1= abs(a[i+1]-a[i]);
            
        }
        if(i!=0){
            mini2=abs(a[i]-a[i-1]);
        }
        mini= min(mini1,mini2);
        max1= abs(a[i]-a[0]);
        max2= abs(a[i]-a[n-1]);
        maxi= max(max1,max2);
        cout<<mini<<" "<<maxi<<"\n";
    }

}