#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,sx,sy,d;
        cin>>n>>m>>sx>>sy>>d;
       if(abs(sx-1)>d && abs(sy-m)>d){
        cout<< (n+m-2)<<"\n";
       }
       else if(abs(sy-1)>d && abs(sx-n)>d){
        cout<<(n+m-2)<<"\n";
       }
       else{
        cout<<-1<<"\n";
       }


    }
}