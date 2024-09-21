#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    ll n,x;
    cin>>n>>x;
    queue<ll>q1,q2,q3;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q1.push(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q2.push(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        q3.push(x);

    }
    ll cnt=0;
    ll ans=0;
    bool flag=0;
    string res;
    while(q1.empty()==false || q2.empty()==false || q3.empty()==false){
            ll a= (q1.empty()==false)?q1.front():INT_MAX;
            ll b= (q2.empty()==false)?q2.front():INT_MAX;
            ll c= (q3.empty()==false)?q3.front():INT_MAX;
            // cout<<a<<" "<<b<<" "<<c<<"\n";

            if(a<=b && a<=c && (a<=cnt || (a<=x))){
                    ans=a;
                    q1.pop();
                    // cout<<" s1 "<<ans<<"\n";
            }
           else if(c<=b && c<=a &&  (c<=cnt || (c<=x) )){
                    ans=c;
                    q3.pop();
                    // cout<<" s2 "<<ans<<"\n";
            }
             else if(b<=c && b<=a && (b<=cnt|| b<=x)){
                    ans=b;
                    q2.pop();
                    // cout<<" s3 "<<ans<<"\n";
            }
            else if(a>cnt && b>cnt && c>cnt){
                if(cnt!=x){
                flag=1;
                res="No\n";
                break;
                }
                else if(cnt==x){
                    flag=1;
                    res="Yes\n";
                    break;
                }
            }
            cnt=(cnt|ans);
            if(cnt==x){
                flag=1;
                res="Yes\n";
                break;
            }

    }
    if(flag==0){
        res="No\n";
    }
    cout<<res;
    }
}