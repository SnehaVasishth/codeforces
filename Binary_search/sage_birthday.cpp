#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    ll i=0,j=n-1;
    vector<ll>ans;
    while(i<=j){
            ans.push_back(a[j]);
            j--;
            if(i>j){
                break;
            }
            ans.push_back(a[i]);
            i++;
    }
    ll b= ((n&1)==0)?((n/2)-1):(n/2);
    cout<<b<<"\n";
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";

}