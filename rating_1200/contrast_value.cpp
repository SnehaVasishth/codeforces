#include<bits/stdc++.h>
#define ll long long
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
        // vector<int>b;
        // b.push_back(a[0]);
        // set<int>st;
        // for(int i=1;i<=(n-2);i++){
        //     int el=a[i];
        //     if(st.find(el)==st.end()){
        //         b.push_back(el);
        //         st.insert(el);
        //     }
        // }
        // b.push_back(a[n-1]);
       
//         int ans=b.size();
// int m=b.size();
// for(int i=0;i<m;i++){
//     cout<<b[i]<<"\n";
// }

     n= unique(a.begin(),a.end())-a.begin();
     ll ans=n;
for(int i=0;(i+2)<n;i++){
    if((a[i]>a[i+1]) && a[i+1]>a[i+2]){
        ans--;
    }
    else if(a[i]<a[i+1] && a[i+1]<a[i+2]){
        ans--;
    }

}
cout<<ans<<"\n";
     
    }
}