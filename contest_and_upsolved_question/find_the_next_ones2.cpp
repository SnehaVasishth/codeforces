#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n+1),next(n+1,n+1);
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }

        int q;
        cin>>q;
        vector<pair<int,int>>query(q+1);
        for(int i=1;i<=q;i++){
            cin>>query[i].first;
            cin>>query[i].second;
        }
        for(int i=n-1;i>=1;i--){
            next[i]=(a[i]==a[i+1])?next[i+1]:(i+1);
        }

        for(int i=1;i<=q;i++){
            int l=query[i].first;
            int r=query[i].second;
            if(next[l]<=r){
                cout<<l<<" "<<next[l]<<"\n";
            }
            else{
                cout<<-1<<" "<<-1<<"\n";
            }
        }

        
    }
}


