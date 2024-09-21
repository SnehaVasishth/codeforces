#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            pq.push(x);
        }
        ll sum=0;
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            pq.pop();
            pq.push(x);
        }
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        cout<<sum<<"\n";
    }
}