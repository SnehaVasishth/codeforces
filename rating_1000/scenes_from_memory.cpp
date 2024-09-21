#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool prime(int n){
    vector<bool>isprime(n+1,true);
    isprime[0]=false,isprime[1]=false;
    for(int i=2;i*i<=n;i++){
        if(isprime[i]){
            for(int j=i*i;j<=n;j+=i){
                isprime[j]=false;
            }
        }


    }
    return isprime[n];
}
void solve(int k,string &s){
    int ans=0;

    for(int i=0;i<k;i++){
        if(s[i]=='1' || s[i]=='4' || s[i]=='6'  || s[i]=='8' || s[i]=='9'){
            cout<<1<<"\n";
            cout<<s[i]<<"\n";
            return ;
        }
    }

    for(int i=0;i<k;i++){
        for(int j=i+1;j<k;j++){
            if(prime(((s[i]-'0')*10) + (s[j]-'0'))==false){
                cout<<2<<"\n";
                cout<<s[i]<<s[j]<<"\n";
                return;
            }
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int k;
        cin>>k;
        string s;
        cin>>s;
        solve(k,s);
    }
}
