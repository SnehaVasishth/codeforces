#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string given;
        cin>>given;
        string s;
        s=given[0];
        int cnt=1;
        int k=1;
        while(s!=given){
            bool flag=0;
            string m="";
            for(k;k<n;k++){
                m+=given[k];
                // cout<<"sneha "<<m<<"\n";
                // cout<<"kanha "<<cnt<<"\n";
                if(s.find(m)!=string::npos){
                    flag=1;
                    continue;

                }
                if(s.find(m)==string::npos && flag==1){
                    s+=m;
                    s.pop_back();
                    cnt++;
                    // cout<<"aashi "<<s<<"\n";
                    // cout<<"kyavalue "<<cnt<<"\n";
                    flag=0;
                    break;
                }
                else if((s.find(m)==string::npos)&&flag==0){
                    s+=m;
                    cnt++;
                    k++;
                    // cout<<"ddde "<<s<<"\n";
                    // cout<<"kya "<<k<<"\n";
                    break;

                }
            }
            if(flag==1){
                cnt++;
                s+=m;
            }
        }
       
        if(cnt<n){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

    }
}