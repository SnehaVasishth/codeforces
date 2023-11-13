#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        int cnt1=0;
        int cnt2=0;
        for(int i=0;i<=n-2;i++){
            if(s[i]=='A' && s[i+1]=='B'){
                s[i]='B';
                s[i+1]='C';
                cnt1++;
                
        }
         if(s[i]=='B' && s[i+1]=='A'){
                s[i]='C';
                s[i+1]='B';
                cnt1++;
        
    }
}
 for(int i=n-2;i>=1;i--){
            if(s[i]=='B' && s[i-1]=='A'){
                s[i]='C';
                s[i-1]='B';
                cnt2++;
                
        }
         if(s[i]=='A' && s[i-1]=='B'){
                s[i]='B';
                s[i+1]='C';
                cnt2++;
        
    }
    
}
cout<<max(cnt1,cnt2)<<"\n";

    }
    
    
    }