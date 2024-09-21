#include<bits/stdc++.h>

using namespace std;
int K;
int mini;
void solve(vector<int>&res,int a){
    if(a==mini || K==0){
        res.push_back(a);
        return;

    }
    else if(a!=mini && K!=0){
        K--;
        solve(res,a-mini);
        solve(res,mini);
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        K=3;
        int a,b,c;
        cin>>a>>b>>c;
        vector<int>res;
        mini= min(a,min(b,c));
        if(a!=mini){
            solve(res,a);
        }
        if(b!=mini){
            solve(res,b);
        }
        if(c!=mini){
            solve(res,c);
        }

        bool flag=0;
        for(int i=0;i<res.size();i++){
            if(res[i]!=mini){
                cout<<"NO\n";
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<"YES\n";
        }
    }


}