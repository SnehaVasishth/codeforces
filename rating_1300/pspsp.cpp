#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a;
        cin>>a;

        bool p=0,s=0;
        if(a[0]=='s')a[0]='.';
        if(a[n-1]=='p')a[n-1]='.';

        for(int i=0;i<n;i++){
            if(a[i]=='s')s=1;
            if(a[i]=='p')p=1;
            if(s && p)break;
        }

        if(s&&p)cout<<"NO\n";
        else cout<<"YES\n";
    }
}