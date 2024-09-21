#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
       vector<vector<int>>m(n,vector<int>(n));
    ll el= (1<<30)-1;
        for(int i=0;i<n;i++){
            v[i]=el;
            
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>m[i][j];
                if(i!=j){
                    v[i]=(v[i]&m[i][j]);
                    v[j]=(v[j]& m[i][j]);
                }

            }
        }

        bool res=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j && ((v[i] | v[j])!= m[i][j])){
                    res=false;
                    break;
                }
            }
        }
        if(res==true){
            cout<<"YES"<<"\n";
            for(auto it:v){
                cout<<it<<" ";
            }
            cout<<"\n";
        }
        else{
            cout<<"NO"<<"\n";
        }
    }
}