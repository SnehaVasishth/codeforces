#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n+1);

        for(int i=1;i<=n;i++){
            cin>>v[i];
        }

        string s;
        cin>>s;
        vector<int>ans(n+1);
        for(int i=1;i<=n;i++){
            int cnt=0;
            int par=i;
            if(s[par-1]=='0'){
            cnt++;
            }
            par=v[par];
            while(par!=i){
                if(par<i)
                break;
                if(s[par-1]=='0')
                cnt++;
                par=v[par];
            }
            // cout<<" value "<<cnt<<"\n";
            if(par<i){
                ans[i]=ans[par];
            }
            else
        ans[i]=cnt;
        }

        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}