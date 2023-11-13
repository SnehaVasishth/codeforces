#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;

        vector<int>a(n);
        vector<int>ans;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            if(a[i]>=k){
                a[i]=a[i]%k;
                
            }
        }
        for(int i=0;i<n;i++){
            if(a[i]==0){
                ans.push_back(i+1);

            }
        }
       vector<pair<int,int>>b(n);
       for(int i=0;i<n;i++){
        b[i].first=a[i];
        b[i].second=i+1;
       }
       
       stable_sort(b.rbegin(),b.rend());
       
        for(int i=0;i<n;i++){
            if(b[i].first!=0){
                ans.push_back(b[i].second);
            }


        }
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<"  ";
        }
        cout<<"\n";
    }
}