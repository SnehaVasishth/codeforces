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
        vector<bool>mark(n+1,0);

        for(int i=1;i<=n;i++){
            cin>>v[i];
        }

        string s;
        cin>>s;
        vector<vector<int>>ans;
        int pre;
        for(int i=1;i<=n;i++){
            vector<int>res;
            int cnt=0;
            if(mark[i]==0){
                res.push_back(i);
                mark[i]=1;
                pre=v[i];
                if(s[i-1]=='0')
                cnt++;

                while(pre!=i){
                    if(mark[pre]==0){
                    res.push_back(pre);
                    mark[pre]=1;
                    if(s[pre-1]=='0')
                    cnt++;

                    pre=v[pre];

                    }
                    else{
                        break;
                    }

                }
                res.push_back(cnt);
                ans.push_back(res);

            }
        }

        vector<int>final(n+1);
        for(int i=0;i<ans.size();i++){
            for(int j=0;j<(ans[i].size()-1);j++){
                final[ans[i][j]]=ans[i][ans[i].size()-1];

            }
        }

        for(int i=1;i<=n;i++){
            cout<<final[i]<<" ";
        }
        cout<<"\n";
    }
}