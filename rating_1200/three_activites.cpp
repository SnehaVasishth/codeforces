#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> solve(vector<int>&a,int n){
    priority_queue<pair<int,int>>pq;
    vector<int>ans;

    for(int i=0;i<n;i++){
        pq.push({a[i],i});
    }
    int k=3;
    while(k){
        ans.push_back(pq.top().second);
        pq.pop();
        k--;

    }
    return ans;
    


}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n),b(n),c(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        vector<int>a_max=solve(a,n);
         vector<int>b_max=solve(b,n);
          vector<int>c_max=solve(c,n);

          ll maxi=0;

          for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(a_max[i]!=b_max[j] && a_max[i]!=c_max[k] && b_max[j]!=c_max[k]){
                        ll sum= a[a_max[i]]+b[b_max[j]]+c[c_max[k]];
                        maxi=max(maxi,sum);
                    }
                }
            }
          }
          cout<<maxi<<"\n";

    }
}