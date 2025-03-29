#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        char c;
        cin>>c;
        string s;
        cin>>s;
       int y;
        bool flag=0;
        for(int i=0;i<n;i++){
            if(s[i]!=c)
            {
                flag=1;
                break;
            }
        }
        if(flag==0){
            cout<<0<<"\n";
        }
        else{
        for(int x=1;x<=n;x++){
              flag=0;
              for(int j=x-1;j<n;j+=x){
                if(s[j]!=c){
                    flag=1;
                    break;
                }
              }
              if(flag==0){
                y=x;
                break;
              }


        }
        if(flag==1){
            cout<<2<<"\n";
            cout<<n-1<<" "<<n<<"\n";
        }
        else{
            cout<<1<<"\n";
            cout<<y<<"\n";
        }
        }
    }
}