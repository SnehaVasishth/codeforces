#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string>v(n);
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            v[i]=s;
        }
        vector<int>ans(n);
        int last=0,pehle=0;

        for(int i=0;i<n;i++){
            last=0;
            pehle=0;
            for(int j=0;j<n;j++){
                if(i==j)
                continue;

                else if(i>j){
                    if(v[i][j]=='0'){
                        last++;
                        
                    }
                    else{
                        pehle++;
                    }
                }
                else if(i<j){
                    if(v[i][j]=='0'){
                        pehle++;
                    }
                    else{
                        last++;
                    }
                }
            }
            ans[pehle]=i+1;
        }

        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";
    }
}