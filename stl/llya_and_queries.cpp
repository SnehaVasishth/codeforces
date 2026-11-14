#include<bits/stdc++.h>
using namespace std;

void solve(vector<vector<int>>&v,int m,string &s){
    int n=s.size();
    vector<int>p(n,0);
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1])
        p[i]=p[i-1]+1;
        else
        p[i]=p[i-1];

    }
    for(int i=0;i<m;i++){
        int l= v[i][0];
        int r=v[i][1];
        cout<<(p[r-1]-p[l-1])<<"\n";
    }

}

int main(){
    string s;
    cin>>s;
    int m;
    cin>>m;
    vector<vector<int>>v(m,vector<int>(2));
    for(int i=0;i<m;i++){
        for(int j=0;j<2;j++){
            cin>>v[i][j];
        }
    }
    solve(v,m,s);
}