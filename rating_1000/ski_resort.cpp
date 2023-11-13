#include<bits/stdc++.h>

using namespace std;
int main(){
   long long int t;
    cin>>t;
    while(t--){
      long long  int n,k,q;
        cin>>n>>k>>q;
        vector<long long int>in(n);
        for(long long int i=0;i<n;i++){
            cin>>in[i];
        }
       
       
        vector<long long int>d;
       long long int ind=0;
        long long int i;
        for(i=0;i<n;i++){
            if(in[i]>q && d.size()==0){
              long long   int formula=i-ind;
                ind=i;
                d.push_back(formula);
            }
            if(in[i]>q && d.size()>0){
               long long  int formula=i-ind-1;
                ind=i;
                d.push_back(formula);
            }
        }
        if(i==n && d.size()>0){
            d.push_back(i-ind-1);
        }
        else{
            d.push_back(i-ind);
        }
       
        
    long long int sum=0;
       
        for(long long int j=0;j<d.size();j++){
            if(d[j]>=k && d[j]>0){
               long long int b=d[j]-k+1;
               long long int l=1;
                long long int d=-1;
                long long int m=((l-b)/d )+1;
                sum=sum+(m*(b+l))/2;
                
            }
          


        }
          cout<<sum<<"\n";
        

    }
}