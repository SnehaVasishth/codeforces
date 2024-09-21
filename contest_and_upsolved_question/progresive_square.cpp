#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool check( vector<vector<int>>&a,vector<int>&v){
unordered_map<int,int>mp1,mp2;
int n=a.size();
for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
        mp1[a[i][j]]++;
    }
}
for(int i=0;i<n*n;i++){
    mp2[v[i]]++;
}
return (mp1==mp2);

}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,c,d;
        cin>>n>>c>>d;
        vector<vector<int>>a(n,vector<int>(n,0));
        vector<int>v(n*n);
        int a1=INT_MAX;
        for(int i=0;i<n*n;i++){
            cin>>v[i];
            if(v[i]<a1){
                a1=v[i];
            }
        }

a[0][0]=a1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0){
                  continue;
                }
                if(j==0 && i!=0){
                    a[i][j]= a[i-1][0]+c;
                }
                else{
                    a[i][j]=a[i][j-1]+d;
                }
            }
        }
      

       

        bool ans=check(a,v);
        if(ans)
        cout<<"YES\n";
        else{
            cout<<"NO\n";
        }
    }
}