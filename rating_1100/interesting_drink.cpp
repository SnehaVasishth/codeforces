#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int q;
    cin>>q;
    vector<int>a(q);
    for(int i=0;i<q;i++){
        cin>>a[i];
    }
    sort(v.begin(),v.end());
    for(int i=0;i<q;i++){
        int x=a[i];
        int low=0,high=n-1;
        while(low<=high){
            int mid= low+(high-low)/2;
            if(v[mid]<=x){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        cout<<low<<"\n";
    }
}