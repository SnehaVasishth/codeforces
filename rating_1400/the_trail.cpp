#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        vector<vector<ll>>v(n,vector<ll>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
            }
        }
        v[0][0]=-1e15;
        int k=0,j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='D'){
                k++;
                v[k][j]=-1e15;
            }
            else{
                j++;
                v[k][j]=-1e15;
            }

        }

        for(int i=0;i<n;i++){
            ll sum=0,tot=0,r=-1,c=-1;
            for(int j=0;j<m;j++){
                if(v[i][j]==-1e15){
                    tot++;
                    r=i;
                    c=j;
                }
                else{
                    sum+=v[i][j];
                }
            }
            if(tot==1){
                v[r][c]=-sum;
            }
        }

        for(int j=0;j<m;j++){
            ll sum=0,tot=0,r=-1,c=-1;
            for(int i=0;i<n;i++){
                if(v[i][j]==-1e15){
                    tot++;
                    r=i;
                    c=j;
                }
                else{
                    sum+=v[i][j];
                }
            }
            if(tot==1){
                v[r][c]=-sum;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<v[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
}