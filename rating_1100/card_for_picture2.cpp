#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll c;
        cin>>c;
        vector<ll>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        ll low=1;
        ll high= 1e9;
        ll sum=0;
        while(low<=high){
            ll mid= low+(high-low)/2;
            sum=0;
            for(int i=0;i<n;i++){
                sum+=(v[i]+2*mid)*(v[i]+2*mid);
                if(sum>c){
                    break;
                }
            }
            if(sum==c){
                cout<<mid<<"\n";
                break;
            }
            else if(sum<c){
                low= mid+1;
            }
            else{
                high=mid-1;
            }
        }

    }
}