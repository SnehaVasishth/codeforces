#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s;
        cin>>n>>s;
        vector<int>a(n),p(n);
        ll sum=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
            
        }
        for(int i=0;i<n;i++){
            sum+=a[i];
            p[i]=sum;
        }
sum=0;
int r=0;
int maxi=-1;
int l=0;
        for(l=0;l<n;l++){
            int l1=l;
            int r1=n-1;
            while(l1<=r1){
                int m= (r1+l1)/2;
            sum=p[m]-p[l]+a[l];
            if(sum>s){
                r1=m-1;
            }
            else if(sum<=s){
                l1=m+1;
            }
            }
            r=r1;
            int ans= p[r]-p[l]+a[l];
           
           
            if(ans==s){
                maxi=max(maxi,r-l+1);
            }



        }
        
        if(maxi==-1){
            cout<<-1<<"\n";
        }
        else{
            cout<<(n-maxi)<<"\n";
        }


    }
}