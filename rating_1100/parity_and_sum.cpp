#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>a(n);
        ll badhaodd=-1,evencount=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]&1){
                if(badhaodd<a[i]){
                    badhaodd=a[i];
                }
            }
            else{
                evencount++;
                pq.push(a[i]);
            }
        }
    if(evencount==n){
        cout<<0<<"\n";
    }
    else{
        ll cnt=evencount;
        while(!pq.empty()){
            if(pq.top()<badhaodd){
                badhaodd=badhaodd+pq.top();
                pq.pop();
                
            }
            else if((pq.empty()==false) && pq.top()>badhaodd){
               cnt++;
               break;
            }
        }
        cout<<cnt<<"\n";
    }
    }
}