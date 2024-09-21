#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll x;
        cin>>x;
        string num= to_string(x);
        int n=num.size();
        // cout<<num<<" size "<<n<<"\n";
        if(n<=2){
            cout<<"NO\n";
            continue;
        }
        string no= num.substr(2);

        ll numb= stoi(no);
        // cout<<" number "<<numb<<"\n";
        // cout<<num[2]<<" kya \n";

        if(n>=3 && num[0]=='1' && num[1]=='0' && (num[2]!='0') && numb>=2){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}