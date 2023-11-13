#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    int x,y;
    vector<int>m(n);
    vector<string>s;
    for(int i=0;i<n;i++){
        
        cin>>m[i];
        string ans;
        cin>>ans;
         s.push_back(ans);
    }
    
    int ans= INT_MAX;
    int ans1=INT_MAX;
    int ans2= INT_MAX;
    int res=0;
    for(int i=0;i<n;i++){
        if(s[i]=="11"){
            if(ans>m[i]){
                ans= m[i];
            }
        }
        else if(s[i]=="10"){
            if(ans1>m[i]){
                ans1=m[i];
            }
        }
         else if(s[i]=="01"){
            if(ans2>m[i]){
                ans2=m[i];
            }
        }
    }
   if(ans==INT_MAX && ans1!=INT_MAX && ans2==INT_MAX){
    cout<<-1<<"\n";
   }
   if(ans==INT_MAX && ans1==INT_MAX && ans2!=INT_MAX){
    cout<<-1<<"\n";
   }
   if(ans!=INT_MAX && ans1!=INT_MAX && ans2==INT_MAX){
    cout<<ans<<"\n";
   }
   if(ans!=INT_MAX && ans2!=INT_MAX  && ans1==INT_MAX){
    cout<<ans<<"\n";
   }
   if(ans!=INT_MAX && ans1!=INT_MAX && ans2!=INT_MAX ){
    if(ans<(ans1+ans2)){
        cout<<ans<<"\n";
    }
    else 
    cout<<(ans1+ans2)<<"\n";
   }
if(ans1!=INT_MAX && ans2!=INT_MAX && ans==INT_MAX){
    cout<<(ans1+ans2)<<"\n";
}
if(ans!=INT_MAX && ans1== INT_MAX && ans2== INT_MAX){
    cout<<ans<<"\n";
}
    }

}