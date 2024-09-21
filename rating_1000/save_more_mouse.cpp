#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int hole,n;
        cin>>hole>>n;
        vector<int>mice(n);
        for(int i=0;i<n;i++){
            cin>>mice[i];
        }

        ll stepm=0,c=0,rat=0;

        sort(mice.begin(),mice.end(),greater<int>());
        for(int i=0;i<n;i++){

            if(mice[i]>c){
                stepm= (hole-mice[i])+stepm;
                c=c+(hole-mice[i]);
                rat++;

            }
            else if(mice[i]<=c){
                break;
            }
        }
        cout<<rat<<"\n";
    }
}