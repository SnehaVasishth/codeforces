#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int>v(n);
        // priority_queue<int>pq;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            v[i]=x;
            // pq.push(x);
        }
        int big= *max_element(v.begin(),v.end());
        int sum=0;
        int cnt=0;
        int flag=0;
        int height=big;
        while(big>0){
            int now=big;
            sum=0;
           
            for(int i=0;i<n;i++){
                if(v[i]<=now){
                    sum+=(now-v[i]);
                }
            }
            cnt++;
            if(sum==x){
                height=now;
                flag=1;
                break;

            }
            if(sum<x && cnt==1){
                flag=2;
                height=now;
                break;
            }
            if(sum<x && cnt>1){
                flag=3;
                height=now;
                break;
            }
            big--;
        }
        if(flag==1 || flag==3){
            cout<<height<<"\n";
        }
        else if(flag==2){
            int amount=x-sum;
            int ans=amount/n;
            ans= ans+height;
            cout<<ans<<"\n";
        }
    }
}