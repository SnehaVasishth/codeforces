#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>a(n);
        unordered_map<ll,ll>mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
           
        }
       sort(a.begin(),a.end());
        ll maxi=1;
       ll use=n;
       
        
        for(ll a1=n;a1>=1;a1--){
            bool flag=0;
               ll cnt=0;

        for(int j=1;j<n;j++){
               ll ans= abs(a[0]-a[j]);

               if(ans<=0){
                continue;
               }
               else if((flag==0)){

                
                ll a2= abs(a1-ans);
                if((a1+a[0])==(a2+a[j])  && (mp.find(a1)==mp.end()) &&(mp.find(a2)==mp.end()) && a2>=1 && a2<=n){
                    
                        cnt+=2;
                        mp[a1]=a[0];
                        mp[a2]=a[j];
                        flag=1;
                      
                }
                

               }
               else if((flag==1)){
                ll a2= abs(a1-ans);
                if((a1+a[0])==(a2+a[j]) && a2>=1 && a2<=n  && (mp.find(a2)==mp.end())){
                    cnt++;
                    mp[a2]=a[j];
                }

               }

               
              
               }
               maxi=max(maxi,cnt);
        }
        
       
    
      cout<<maxi<<"\n";


    }
}