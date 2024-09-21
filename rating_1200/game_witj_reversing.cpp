#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s,t,rev_t;
        cin>>s>>t;
        rev_t=t;

        reverse(rev_t.begin(),rev_t.end());
        ll ans1=0,ans2=0,cnt1=0,cnt2=0;
        for(int i=0;i<n;i++){
            if(s[i]!=t[i]){
                cnt1++;

}

        if(s[i]!=rev_t[i]){
            cnt2++;
        }
        }

        if(cnt1%2==0){
            ans1= 2*cnt1;
        }
        else if((cnt1&1)!=0){
            ans1=2*cnt1-1;
        }
        if(t==rev_t){
            ans1=2*cnt1-1;
        }
        if(cnt2%2==0){
            ans2=2*cnt2;
            ans2+=2;
        }
        else if((cnt2&1)!=0){
            ans2=cnt2*2-1;
            ans2+=2;
        }
        if(t==rev_t){
            ans2=2*cnt2-1;
            ans2+=2;
        }

        ans1=min(ans1,ans2);
        cout<<ans1<<"\n";
    }
}