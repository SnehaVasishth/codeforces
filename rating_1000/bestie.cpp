#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n+1);
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>v[i];
            ans= __gcd(ans,v[i]);

        }
        int cost=0;
        int res;
       
            for(int i=n;i>=1 && ans!=1 ;i--){
                res=__gcd(i,v[i]);
                if(res==ans){
                    continue;
                }
                else if(res!=ans){
                    v[i]=res;
                    cost=n-i+1+cost;
                    ans=__gcd(ans,res);
                }

            }
        cout<<cost<<"\n";
    }
}