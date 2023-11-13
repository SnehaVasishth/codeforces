#include<bits/stdc++.h>

using namespace std;
int main(){
    long long int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        vector<long long int>a(n,-1);
        vector<long long int>prime;
        unordered_set<long long int>s;
        bool flag=0;
        for(long long int i=2;i<=n;i++){
            flag=0;
            for(long long j=2;j*j<=i;j++){
                if(i%j==0){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                prime.push_back(i);
            }

        }
        a[n/2]=1;
        s.insert(1);
        long long  i,k=0;
        for(i=0;i<n/2;i++){
            if(k<prime.size()){
                a[i]=prime[k];
               
                s.insert(prime[k]);
                 k++;
                
            }
            if(k<prime.size()){
                a[n-i-1]=prime[k];
            
                s.insert(prime[k]);
                    k++;
                   
            }
            if(k>=prime.size()){
               
                break;
            }
           
        }
        
        for(long long  l=1;l<=n;){
            if(s.find(l)==s.end()){
                i++;
                if(a[i]==-1){
                    a[i]=l;
                    s.insert(l);
                    l++;
                    
                }
               
            }
             else{
                    l++;
                }

           
        }
       
      for(long long  i=0;i<n;i++){
        cout<<a[i]<<" ";
      }
        cout<<"\n";

    }
}