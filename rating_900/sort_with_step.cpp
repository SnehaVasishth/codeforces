#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<pair<int,int>>v;
        for(int i=1;i<=n;i++){
            int x;
            cin>>x;
            if(abs(x-i)%k==0){
                continue;
            }
            else if(abs(x-i)%k!=0){
                v.push_back({x,i});
            }
        }
        if(v.size()==0){
            cout<<0<<"\n";
        }
        else if(v.size()==2){
            if((abs(v[1].first-v[0].second)%k==0) && (abs(v[0].first-v[1].second)%k==0)){
                cout<<1<<"\n";
            }
            else{
                cout<<-1<<"\n";
            }
        }
        else if(v.size()==1 || v.size()>2){
            cout<<-1<<"\n";
        }
    }
}