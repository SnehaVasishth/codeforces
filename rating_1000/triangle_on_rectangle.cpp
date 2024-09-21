#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int w,h;
        cin>>w>>h;
        int k1;
        cin>>k1;
        vector<int>x_axis(k1);
        for(int i=0;i<k1;i++){
            cin>>x_axis[i];
        }
        int k2;
        cin>>k2;
        vector<int>h_axis(k2);
        for(int i=0;i<k2;i++){
            cin>>h_axis[i];
        }
        int k3;
        cin>>k3;
        vector<int>y_axis(k3);
        for(int i=0;i<k3;i++){
            cin>>y_axis[i];

        }
        int k4;
        cin>>k4;
        vector<int>w_axis(k4);
        for(int i=0;i<k4;i++){
            cin>>w_axis[i];
        }

        ll ans=0,maxi=INT_MIN;

        int small= x_axis[0];
        int large= x_axis[k1-1];
        ll dis= abs(small-large);
        ans= (dis)*(h);
        maxi= max(maxi,ans);
        small = h_axis[0];
        large= h_axis[k2-1];
        dis= abs(small-large);
        ans=(dis)*h;
        maxi=max(maxi,ans);

        small= y_axis[0];
        large=y_axis[k3-1];
        dis= abs(large-small);
        ans= (dis)*w;
        maxi=max(maxi,ans);

        small= w_axis[0];
        large=w_axis[k4-1];
        dis= abs(large-small);
        ans= (dis)*w;
        maxi=max(maxi,ans);

        cout<<maxi<<"\n";

    }
}