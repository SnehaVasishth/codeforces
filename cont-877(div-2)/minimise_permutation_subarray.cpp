#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        int idx1,idx2,idxn;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[i]=x;
            if(a[i]==1){
                idx1=i;
            }
            else if(a[i]==2){
                idx2=i;
            }
            else if(a[i]==n){
                idxn=i;
            }
        }
        if(idxn>idx1 && idxn>idx2){
            int ans= max(idx1,idx2);
            cout<<(ans+1)<<" "<<(idxn+1)<<"\n";
        }
        else if(idxn<idx1 && idxn<idx2){
            int ans= min(idx1,idx2);
            cout<<(idxn+1)<<" "<<(idx1+1)<<"\n";
        }
        else{
            int ans= min(idx1,idx2);
            if(ans==idx1){
                cout<<(ans+1)<<" "<<(idx2+1)<<"\n";
            }
            else if(ans==idx2){
                cout<<(ans+1)<<" "<<(idx1+1)<<"\n";
            }
        }
    }
}