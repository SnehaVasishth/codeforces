#include<bits/stdc++.h>
using namespace std;
int fun(vector<int> &a, vector<int> &b,int act_time, int n){
    int curr_time=a[0];
    int ent= b[0];
    act_time= act_time-1;
    int index=0;
 int mini= *min_element(a.begin(),a.end());
 if(mini>act_time){
    return -1;
 }
   else{

    for(int i=1;i<n;i++){
        if(b[i]>ent && a[i]<=act_time){
            index=i;
            curr_time=a[i];
            ent= b[i];
            act_time--;
           
        }
        else{
            act_time--;
        }
    }
  
    

return(index+1);
   }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,act_time;
        cin>>n>>act_time;
        vector<int>a(n);
        vector<int>b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
         for(int i=0;i<n;i++){
            cin>>b[i];
        }
int ans= fun(a,b,act_time,n);
cout<<ans<<"\n";
    }
    }
