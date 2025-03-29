#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<char>>a(n,vector<char>(n));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>a[i][j];
            }
        }

        int cnt=0;

        for(int i=0;i<n/2;i++){
            for(int j=i;j<n-1-i;j++){
                int one=a[i][j]-'0';
                int two= a[n-1-i][n-1-j]-'0';
                int three=a[j][n-1-i]-'0';
                int four= a[n-1-j][i]-'0';
                int sum= one+two+three+four;
                cnt=cnt+min(sum,4-sum);
            }
        }
        cout<<cnt<<"\n";
    }
}