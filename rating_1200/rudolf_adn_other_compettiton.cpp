#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
ll n,m,h;
cin>>n>>m>>h;
pair<ll,ll>rud;
ll ans=1;
for(int i=0;i<n;i++){
    ll task=0,sum=0,penalty=0;
    vector<ll>curr(m);
    for(int j=0;j<m;j++){
        cin>>curr[j];
    
    }
    sort(curr.begin(),curr.end());

    for(int j=0;j<m;j++){
        if(sum+curr[j]>h)
        break;
        sum+=curr[j];
        penalty+=sum;
        task++;
    }
    if(i){
        if(make_pair(-task,penalty)<rud){
            ans++;
        }
    }
    else{
        rud={-task,penalty};
    }
}

cout<<ans<<"\n";

}
}