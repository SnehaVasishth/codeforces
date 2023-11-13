#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,n;
        cin>>a>>b>>n;
        vector<int>x(n);
        for(int i=0;i<n;i++){
            cin>>x[i];
        }
        int t=0;
        int m=b;
        for(int i=0;i<n;i++){
            while(m>0){
                m--;
                t++;
            }
            if(m==0 && m+x[i]<a){
                m=m+x[i];
            }
            else if(m==0 && m+x[i]>=a){
                m=a;
            }
        }
        cout<<t<<"\n";
    }
}