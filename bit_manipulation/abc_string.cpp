#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int open=0;
       
       int n=s.size();
        for(int i=1;i<=6;i++){
            int a= (1&(i>>2));
            int b=(1&(i>>1));
            int c= (i&1);
            // if(i==4){
            //     cout<<a<<"\n";
            //     cout<<b<<"\n";
            //     cout<<c<<"\n";
            // }
            bool flag=0;
           open=0;
            for(int i=0;i<n;i++){
                if(open<0){
                    flag=1;
                    break;

                }
                if(s[i]=='A'){
                    (a==0)?(open-=1):(open+=1);
                    // cout<<"a "<<open<<"\n";
                }
                else if(s[i]=='B'){
                    (b==0)?(open-=1):(open+=1);
                    // cout<<"b "<<open<<"\n";
                }
                 else if(s[i]=='C'){
                    (c==0)?(open-=1):(open+=1);
                    // cout<<"c "<<open<<"\n";
                }
            }
            if(open==0){
                cout<<"YES\n";
                break;
            }
        }
        if(open!=0){
            cout<<"NO\n";
        }
    }
}