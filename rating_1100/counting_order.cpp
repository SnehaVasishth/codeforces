#include<bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
using namespace std;

int count(vector<int>&a,int k){
    int n=a.size();
    int l=0;
    int h= n-1;
    int ans=0;
    while(l<=h){
        int mid= l+(h-l)/2;
        if(a[mid]<=k){
            l=mid+1;
        }
        else if(a[mid]>k){
            ans= mid;
            h= mid-1;

        }

    }
    return (n-1-h);
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        ll cnt=0,ways=0,res=1;
        for(int i=n-1;i>=0;i--){
           
            int k= b[i];
            ways= count(a,k);
            ways-=cnt;
            cnt++;
            res=((res*ways)% MOD);
            
        }

        cout<<res<<"\n";

    }
}