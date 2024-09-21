#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>s(n),cnt(n+1,0),sumcnt(n+1,0);

        for(int i=0;i<n;i++){
             cin>>s[i];
             cnt[s[i]]++;


        }

        for(int i=1;i<=n;i++){
            sumcnt[i]=sumcnt[i-1]+cnt[i-1];
        }
        ll sum1=0,sum2=0,totalsum=0;

        for(int i=0;i<=n;i++){
            if(cnt[i]>=2){
                sum1= (((cnt[i]*(cnt[i]-1))/2)*(sumcnt[i]));
                sum2= ((cnt[i])*(cnt[i]-1)*(cnt[i]-2))/6;
                totalsum+=(sum1+sum2);
            }
        }
        cout<<totalsum<<"\n";
           

        
    }
}