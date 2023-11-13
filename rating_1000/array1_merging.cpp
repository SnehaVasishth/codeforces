#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>b(n);
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
         for(int i=0;i<n;i++){
            cin>>b[i];
        }
        vector<long long int>cnt1((2*n+1),0);
        vector<long long int>cnt2((2*n+1),0);
        for(int i=0;i<n;i++){
            int j=i;
            while(j<n && a[i]==a[j]){
                j++;
            }
           long long int l1=j-i;
            cnt1[a[i]]=max (cnt1[a[i]],l1);
            i=j-1;
        }
          for(int i=0;i<n;i++){
            int j=i;
            while(j<n && b[i]==b[j]){
                j++;
            }
           long long int l1=j-i;
            cnt2[b[i]]=max (cnt2[b[i]],l1);
            i=j-1;
        }
        long long int ans= INT_MIN;
        for(int i=1;i<=2*n;i++){
            ans= max(ans,cnt1[i]+cnt2[i]);
        }
cout<<ans<<"\n";

    }
}