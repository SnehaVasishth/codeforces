#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    map<int,int>mp1,mp2;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp1[i]=x;
    }
     for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp2[i]=x;
    }

    int maxi=0,cnt=0;

    int k= 1;
    while(k!=(n-1)){
        for(auto i:mp2){
            cnt=0;

            if(mp1.find(i.second)!=mp1.end()){
                
            }

        }
    }
}