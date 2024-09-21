#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int l= -1,r=INT_MAX;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            int y;
            cin>>y;
            if(x<= k && k<=y){
                l= max(l,x);
                r= min(r,y);
                 
            }
           

        }
        if(l==r){
            cout<<"YES\n";
        }
        else if(l==-1 && r==INT_MAX){
            cout<<"NO\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}