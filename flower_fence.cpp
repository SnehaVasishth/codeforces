#include<bits/stdc++.h>

using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int sum=0;
        vector<int>ans(n);
        vector<int>in(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            ans[i]=x;
            in[i]=x;
            sum=sum+ans[i];
        }
        vector<int>s;
        int count=0;
        while(sum!=0){

            for(int i=0;i<n;i++){
                if(ans[i]!=0){
                    ans[i]=ans[i]-1;
                    count++;
                }
            }
            sum= sum-count;
            s.push_back(count);
            count=0;
            
        }
        // for(int i=0;i<s.size();i++){
        //     cout<<s[i]<<" ";
        // }
        // cout<<"\n";
        bool flag=0;
        // for(int i=0;i<ans.size();i++){
        //     cout<<ans[i]<<" ";
        // }
        // cout<<"\n";
        // for(int i=0;i<s.size();i++){
        //     cout<<s[i]<<" ";
        // }
        // cout<<"\n";
int k;

       for(k=0;k<s.size();k++){

        if(in[k]!=s[k]){
            
            flag=1;
            break;
        }

       }
       if(flag==1){
        cout<<"NO"<<"\n";
       }
       if(flag==0 && k==s.size()){
        cout<<"YES"<<"\n";
       }


    }
}