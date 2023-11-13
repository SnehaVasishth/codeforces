#include<bits/stdc++.h>

using namespace std;
void partition(long long int i,vector<long long int>&a){
    long long int m=i;
    long long int n=a.size();
    long long int pivot=a[i];
   
    long long int j;
    i--;
    vector<long long int>b(n);
b=a;
  
    for(j=i+2;j<n;j++){
        if(b[j]<=pivot){
            i++;
            swap(b[i],b[j]);
        }
    }
   
    long long int k=i+1;
    
    for(long long int l=0;l<n && k<n;l++){
        if(a[l]>=pivot){
            b[k]=a[l];
            k++;
        }

    }
    a=b;
    

}
 int main(){
    long long int t;
    cin>>t;
    while(t--){
        long long int n;
        cin>>n;
        vector<long long int>a(n);
        long long int cnt=0;
        for(long long int i=0;i<n;i++){
            cin>>a[i];
        }
        bool flag=0;
        long long int i=0;
        while(true){
            for(long long int i=0;i<n;i++){
                if(a[i]!=(i+1)){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                cout<<cnt<<"\n";
                break;
            }
            else{
                flag=0;
            }
            if(a[i]>i+1){
                partition(i,a);
                cnt++;     
                 
            }
            else {
                i++;
               
                
            }
              
            

        }
    }
}