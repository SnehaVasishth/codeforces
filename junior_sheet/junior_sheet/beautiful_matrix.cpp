#include<bits/stdc++.h>

using namespace std;
int main(){
    vector<vector<int>>ma(5,vector<int>(5,0));
    int ans;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            int x;
            cin>>x;
            ma[i][j]=x;
            if(x==1){
                ans=abs(i+1-3)+abs(j+1-3);
            }
        }
    }
    cout<<ans<<"\n";

}