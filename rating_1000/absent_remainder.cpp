#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        int x= n/2;
        int idx=0;
        int mini= *min_element(a.begin(),a.end());

        while(x){
            if(a[idx]!=mini){
                cout<<a[idx]<<" "<<mini<<"\n";
               
                 x--;
            }
             idx++;
           
        }
    }
}