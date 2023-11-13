#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string l,r;
        cin>>l>>r;
        int len= r.size()-l.size();
        string s;
        for(int i=0;i<len;i++){
            s+='0';
        }
        s+=l;
        int res=-1;
        for(int i=0;i<r.size();i++){
            if(s[i]!=r[i]){
                res=i;
                break;
            }
        }
        int ans;
        if(res==-1){
            cout<<0<<"\n";
        }
        else{
            ans= 9*(r.size()-res-1);
            ans=ans+abs(s[res]-r[res]);
            cout<<ans<<"\n";
        }

    }
}