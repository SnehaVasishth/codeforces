#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n+1);
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
        for(int i=1;i<=q;i++){
            int l=query[i].first;
            int r=query[i].second;
            bool flag=0;
           for(int j=l+1;j<=r;j++){
            if(a[l]!=a[j]){
                cout<<l<<" "<<j<<"\n";
                flag=1;
                break;
            }
           }
            if(flag==0){
                cout<<-1<<" "<<-1<<"\n";
            }
           
           
        }

    }
}