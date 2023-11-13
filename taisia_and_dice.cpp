#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s,r;
        cin>>n>>s>>r;
        int arr[n];
        arr[0]= s-r;
        int res;
        int d=n;
        int e=n-1;
        for(int i=1;i<=(n-1);i++){
            res= (r/e);
            arr[i]= res;
            r= r-res;
            e--;

        }
        for(int i=0;i<d;i++)
        cout<<arr[i]<<" ";
        cout<<"\n";
    }

}



