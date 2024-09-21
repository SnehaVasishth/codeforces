#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll LCM(int x,int y,ll pro){
    for(ll i=1;i<=pro;i++){
        if((i%x==0)&&(i%y==0))
        return i;
    }
    return pro;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int m,n;
        string s,t;
        cin>>s>>t;
        m=s.size();
        n=t.size();
        ll pro=m*n;
        ll lcm=LCM(m,n,pro);
        int x= lcm/m;
        int y=lcm/n;
        string a,b;
        for(int i=0;i<(x);i++){
            a+=s;
        }
        for(int i=0;i<(y);i++){
            b+=t;
        }
        if(a==b){
            cout<<a<<"\n";
        }
        else{
            cout<<-1<<"\n";
        }
    }
}