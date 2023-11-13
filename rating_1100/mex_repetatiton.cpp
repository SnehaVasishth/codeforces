#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int sum2=0,sum1=0;
        sum1= (n*(n+1))/2;
        deque<int>v;
        for(int i=0;i<n;i++){
          int x;
          cin>>x;
          v.push_back(x);
            sum2=sum2+x;
            
        }
        while(k!=0){
            int missing= sum1-sum2;
            v.push_front(missing);
           int y= v[n];
           sum2=sum2-y+missing;
           v.pop_back();
         
           k--;
            
            
        }
        for(auto &m:v){
            cout<<m<<" ";
        }
        cout<<"\n";
    }
}