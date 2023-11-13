#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool compartor(string &a, string &b){
    return a.size()< b.size();
}
void solve(){
    int n;
    cin>>n;
    vector<string>s(n);
    map<pair<ll,ll>,ll>mp;
    ll ans= n;
for(int i=0;i<n;i++){
    cin>>s[i];
}
sort(s.begin(),s.end(),compartor);
ll sum=0;
for(auto i:s){
    string m =i;
    int x= m.size();
    for(int i=1;i<=x;i++){
        if((i+x)%2!=0)
        continue;
         sum=0;

        ll half= (i+x)/2;
        for(int i=0;i<half;i++) sum+=(m[i]-'0');
        for(int i=half;i<m.size();i++) sum-=(m[i]-'0');
        if(sum>=0){
            ans+= mp[{i,sum}];
        }


    }
    reverse(m.begin(),m.end());
    for(int i=1;i<=x;i++){
        if((i+x)%2!=0)
        continue;
         sum=0;

        ll half= (i+x)/2;
        for(int i=0;i<half;i++) sum+=(m[i]-'0');
        for(int i=half;i<m.size();i++) sum-=(m[i]-'0');
        if(sum>=0){
            ans+= mp[{i,sum}];
        }


    }

    sum=0;
    for(int i=0;i<m.size();i++){
        sum+=(m[i]-'0');
    }
    mp[{m.size(),sum}]++;

}
 cout<<ans<<"\n";

}
int main(){
    solve();
}