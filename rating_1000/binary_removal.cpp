#include<bits/stdc++.h>

using namespace std;

bool solve(string &ans,string &s,int n){
     bool fl=0;
        // cout<<ans<<"\n";

        for(int i=1;i<ans.size();i++){

            if((ans[i]=='0' && ans[i-1]=='1' && (i-1)>=0) || ((ans[i]=='1') && (ans[i+1]=='0') && (i+1)<=n)){
                return false;

            }


        //     if(ans[i]=='0' && fl==0){
        //         if(ans[i-1]=='0'){
        //             // cout<<"aashi\n";
        //             continue;
        //         }
        //         else{
        //             return false;
        //             // cout<<"sneha\n";
                    
        //         }

        //     }
        //     else if(ans[i]=='1' && fl==0){
        //         if(ans[i-1]=='0' && fl==0){
        //             fl=1;
        //             // cout<<"aashi1\n";
        //         }

        //     }
        //     else if(fl==1 && ans[i]=='1'){
        //         if(ans[i-1]=='1'){
        //             // cout<<"aashi2\n";
        //             continue;

        //         }
        //         else{
        //             return false;
        //             // cout<<"aashi3\n";
                   
        //         }
            
        // }
        // else{
        //     return false;
        // }




        }

        return true;
        

}


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int flag=0;
        string ans;
        string ans2;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='0' && flag==0){
                ans.push_back(s[i]);
            }
            else if(s[i]=='1' && flag==0 && ((i+1)<=n-1)){
                ans.push_back(s[i+1]);
                flag=1;
                i++;

            }
            else if(flag==1 && s[i]=='1' && ((i+1)<=n-1)){
                ans.push_back(s[i+1]);
                i++;


            }
            else if(flag==1 && s[i]=='0' && ((i+1)<=n-1)) {
                flag=2;
                ans.push_back(s[i+1]);
                i++;
            }
            else if(flag==2 && s[i]=='0' && ((i+1)<=n-1)){
                ans.push_back(s[i+1]);
                i++;
            }
        }
flag=0;

    for(int i=n-1;i>=0;i--){
        if(s[i]=='1' && flag==0){
            ans2.push_back(s[i]);
        }
        else if(s[i]=='0' && flag==0 &&(i-1)>=0){
            ans2.push_back(s[i-1]);
            flag=1;
            i--;
        }
        else if(s[i]=='0' && flag==1 && (i-1)>=0){
            ans2.push_back(s[i-1]);
            i--;
        }
        else if(s[i]=='1' && flag==1 &&(i-1)>=0){
            ans2.push_back(s[i-1]);
            flag=2;
            i--;
        }
        else if(s[i]=='1' && flag==2 && (i-1)>=0){
            ans2.push_back(s[i-1]);
            i--;
        }

    }
    reverse(ans2.begin(),ans2.end());

  bool res1=  solve(ans,s,n);
  bool res2= solve(ans2,s,n);

  cout<<"asn1  "<<ans<<"  "<<"asn2  "<<ans2<<"\n";
       
       string fin= ((res1|res2)==true)?"YES\n":"NO\n";
       cout<<fin;

        
        


    }
}