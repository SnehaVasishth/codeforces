#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        k--;
        vector<int>a(n),v(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            v[i]=a[i];
            if(i==k){
                swap(a[0],a[k]);
            }
        }
        int ans1=0,ans2=0;

        for(int i=1;i<n;i++){
            if(a[0]>a[i]){
                ans1++;
            }
            else
            break;
        }

        for(int i=0;i<k;i++){
            if(v[i]>v[k]){
                swap(v[i],v[k]);
                k=i;
                break;
            }
        }
        if( (k-1)>=0 && v[k]>v[k-1]){
            ans2=1;
        }
        for(int i=k+1;i<n;i++){
            if(v[i]<v[k])
            ans2++;
            else
            break;
        }

     cout<< max(ans1,ans2)<<"\n";


    }
}