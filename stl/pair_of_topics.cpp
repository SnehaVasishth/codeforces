#include<bits/stdc++.h>
using namespace std;


void solve(vector<int>&a,vector<int>&b,int n){
    vector<int>p(n);
    for(int i=0;i<n;i++){
        p[i]=a[i]-b[i];
    }
    sort(p.begin(),p.end());
//     for(int i=0;i<n;i++)
//     cout<<"val of p "<<p[i]<<"\n";
    long long int cnt=0;
    for(int i=0;i<=(n-2);i++){
        if(p[i]<=0){                                                                                      
        int x= lower_bound(p.begin(),p.end(),(p[i]*-1)+1)-p.begin();
        int val= n-x;
        cnt+=val;
        }
        else
        cnt+=(n-i-1);
    }
    cout<<cnt<<"\n";
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    cin>>b[i];

    solve(a,b,n);
}