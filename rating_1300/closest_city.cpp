#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
int t;
cin>>t;
while(t--){

    ll n;
    cin>>n;
    vector<ll>a(n+1);
    for(ll i=1;i<=n;i++){
        cin>>a[i];

    }
    ll q;
    cin>>q;
    vector<pair<int,int>>query(q);
    for(int i=0;i<q;i++){
        cin>>query[i].first;
        cin>>query[i].second;
    }

    for(int i=0;i<q;i++){
        ll l= query[i].first;
        ll r= query[i].second;
        ll cost=0;

        if(l>=r){
            for(ll j=l ;j>r;j--){
                if(j==n || j==1||  ((a[j]-a[j-1])<= (a[j+1]-a[j]))){
                    cost+=1;
                }
                else if((a[j]-a[j-1])>(a[j+1]-a[j])){
                    cost+=(a[j]-a[l]);
                    break;
                }
            }
            

        }
        else if(l<r){
            for(ll j=l;j<r;j++){
                if(j==1 || j==n || ((a[j+1]-a[j])<=(a[j]-a[j-1]))){
                    cost+=1;

                }
                else if((a[j+1]-a[j])>(a[j]-a[j-1])){
                    cost+=(a[r]-a[j]);
                    break;
                }
            }
        }
        cout<<cost<<"\n";
    }

}
}