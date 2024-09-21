#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
       
        char e=s[0];
        int len=1;
        char maxc;
        int maxi=0;
        for(int i=1;i<n;i++){
            if(e==s[i]){
                len++;

            }
            else{
                    e=s[i];
                    len=1;
            }
            if(len>maxi){
                maxi=len;
                maxc=e;

            }

        }
        int res=n/2,ans=0,cnt=0;
        if(maxi==n){
            ans=n;
        }
     
       else if(maxi>1){
            for(int i=0;i<n;i++){
                if(s[i]==maxc){
                    cnt++;
                }
            }
            
            if(cnt>(res)){
            ans= (n- (2*(n-cnt)));
            }
            else{
                if((n&1)==0){
            ans=0;
           
        }
        else{
            ans=1;
           
        }

            }
        }
        else if((n&1)==0){
            ans=0;
            
        }
        else{
            ans=1;
            
        }
        cout<<ans<<'\n';

    }
}