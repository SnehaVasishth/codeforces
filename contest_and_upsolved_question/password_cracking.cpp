#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        string password="";
        int res;
        ll i=0;
        for(i;i<n;i++){
            string curr= password+'0';
            cout<<"? "<<curr<<endl;
            cout.flush();
            cin>>res;
            if(res==1){
                password.push_back('0');
            }
            else{
                curr=password+'1';
                cout<<"? "<<curr<<endl;
                cout.flush();
                cin>>res;
                if(res==1){
                    password.push_back('1');
                }
                else{
                    break;
                }
            }
        }
        for(;i<n;i++){
            string curr='0'+password;
            cout<<"? "<<curr<<endl;
            cout.flush();
            cin>>res;
          
            if(res==1)
            password='0'+password;
            else{
                password='1'+password;
            }
        }
        cout<<"! "<<password<<"\n";
    }
}