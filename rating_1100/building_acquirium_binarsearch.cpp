#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,w;
        cin>>n>>w;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
     long long    int low=1;
      long long  int high= 1e10;
        
    long long    int idx=-1;
        while(low<=high){
        long long    int mid=low+(high-low)/2;
            long long int sum=0;
            for(int i=0;i<n;i++){
                if(a[i]<mid){
                    sum=sum+(mid-a[i]);
                }
            }
            if(sum<=w){
                idx=mid;
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        cout<<idx<<"\n";

    }
}