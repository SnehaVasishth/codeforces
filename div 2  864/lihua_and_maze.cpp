#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        int ans1,ans2;
        if((x1==1&&y1==1) ||(x1==n && y1==1)||(x1==n && y1==m) ||(x1==1 &&y1==m))
        ans1=2;
        else if(x1==1 || x1==n || y1==1 || y1==m){
            ans1=3;
        }
        else{
           ans1=4;
        }

         if((x2==1&&y2==1) ||(x2==n && y2==1)||(x2==n && y2==m) ||(x2==1 &&y2==m))
        ans2=2;
        else if(x2==1 || x2==n || y2==1 || y2==m){
            ans2=3;
        }
        else{
            ans2=4;
        }
        cout<<min(ans1,ans2)<<"\n";
    }
}