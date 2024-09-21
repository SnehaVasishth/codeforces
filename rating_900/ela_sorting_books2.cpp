#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
       
        int l= n/k;
        map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
       string res="";
       for(int i=1;i<=k;i++){
        char z='a';
        int cnt=0;
        bool flag=0;
        for(int j=0;cnt<l;j++){
            if(mp.find(z)!=mp.end() && mp[z]>0){
                // cout<<z<<"\n";

                mp[z]--;
                cnt++;

                // cout<<"sneha\n";
                // cout<<cnt<<"\n";
            }
            else if((mp.find(z)==mp.end() || mp[z]<=0) && flag==0){
                res+=z;
                flag=1;
            }

            else if((mp.find(z)==mp.end() || mp[z]<=0)){
                char x='a';
                if(mp.find(x)!=mp.end() && mp[x]>0){
                    cnt++;
                    mp[x]--;
                }
                else{
                    x++;
                    while(mp.find(x)==mp.end() || mp[x]<=0){
                        x++;
                    }
                    cnt++;
                    mp[x]--;
                

                // cout<<"aashi"<<"\n";
            }
            }
            z++;

            
            // if(z=='z'){
            //     z='a';
            // }

        }
        
       

           

        
        
        if(flag==0 && res.size()<k){
            res+=z;

        }
       }
       cout<<res<<"\n";

    }
}
