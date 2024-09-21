#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>>v(n,vector<int>(n)),a(n,vector<int>(n));
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    int m=0;
    for(int i=n-1;i>=0;i--){
        int l=0;
        for(int j=n-1;j>=0;j--){
            v[m][l]=a[i][j];
            l++;
        }
        m++;
    }
    int ch=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]!=a[i][j]){
                ch++;
        }
    }

}
// 
if(ch>k){
        cout<<"NO"<<endl;
        return 0;
    }
    k-=ch;
    if(n&1){
        cout<<"YES"<<endl;
    }
    else if(k&1){
        cout<<"NO"<<endl;
    }
    else{
        cout << "YES" << endl;
    }
    }
}


// if(ch>k){
// //     cout<<"NO\n";
// // }
// // else if(ch==k){
// //     cout<<"YES\n";
// // }
// // else if((n&1) && (ch<=k)){
// //     cout<<"YES\n";
// // }
// // else if(ch<k){
// //     ch=k-ch;
// //     if(ch&1){
// //         cout<<"NO\n";
// //     }
// //     else{
// //         cout<<"YES\n";
// //     }
// // }