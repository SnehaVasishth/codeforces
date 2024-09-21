#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
  ll n,p;
    cin>>n>>p;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    ll cost=0,total=p;
    ll cnt=1;
    vector<int>a(n);
    vector<int>b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        pq.push({b[i],a[i]});
    }
//    while(!pq.empty()){
//     cout<<pq.top().first<<" "<<pq.top().second<<"\n";
//     pq.pop();
//    }
    while(cnt!=n){
        int people= pq.top().second;
        cost= pq.top().first;
        pq.pop();
        if(people<=(n-cnt)){
            total+=((cost<p)?(cost*people):(p*people));
            cnt+=people;
        }
        else{
            total+=cost<p?cost*(n-cnt):p*(n-cnt);
            cnt+=(n-cnt);
        }
    }
    cout<<total<<"\n";
}
}
