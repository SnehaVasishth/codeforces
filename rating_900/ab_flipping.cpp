#include<bits/stdc++.h>

using namespace std;

void fun1(int i,int &cnt, string &s){
    for(i;i>=1;i--){
        if(s[i]=='B' && s[i-1]=='A'){
            cnt++;
            swap(s[i],s[i-1]);
        }
    }
}

void fun2(int i,int &cnt,int n, string &s){
    for(i;i<=(n-2);i++){
        if(s[i]=='A' && s[i+1]=='B'){
            cnt++;
            swap(s[i],s[i-1]);

        }
    }

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt=0;
        for(int i=1;i<n;i++){
            if(s[i]=='B' && s[i-1]=='A'){
                cnt++;
                swap(s[i],s[i-1]);
                fun1(i-1,cnt,s);
                fun2(i,cnt,n,s);
                break;
            }
        }
        cout<<cnt<<"\n";
    }
}