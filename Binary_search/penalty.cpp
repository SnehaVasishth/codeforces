#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int cnt1=0,cnt2=0,chance1=5,chance2=5;
        for(int i=0;i<10;i++){
            if(i&1){
                if(s[i]=='1')
                cnt2++;
                 
               
            }
            
            if(((i&1)==0)){
                if(s[i]=='1')
                cnt1++;
                 
               
            }
            if(s[i]=='?'){
                if((i&1)){
                    if((chance2+cnt2)>(chance1+cnt1)){
                        s[i]='1';
                    }
                    else{
                        s[i]='0';
                    }
                }
                if((i&1)==0){
                    if((chance1+cnt1)>=(chance2+cnt2)){
                        s[i]='1';
                    }
                    else{
                        s[i]='0';
                    }
            }
                          

                
            }
            if(i%2){
                chance2=5-((i/2)+1);
            }
            if((i%2)==0){
                chance1=5-((i/2)+1);
            }
        }

        cout<<s<<"\n";
        chance1=5,cnt1=0,chance2=5,cnt2=0;
        for(int i=0;i<10;i++){
            if((i&1)){
                if(s[i]=='1')
                cnt2++;
                chance2=5-((i/2)+1);
            }
            if((i&1)==0){
                if(s[i]=='1')
                cnt1++;
                chance1=5-((i/2)+1);

            }
            if((cnt1)>(cnt2+chance2) || ((cnt2)>(cnt1+chance1))){
                cout<<(i+1)<<"\n";
                break;
            }
        }
    }

}