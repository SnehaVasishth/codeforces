#include<bits/stdc++.h>
#define ll long long

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string a,b;
        cin>>a>>b;
        ll ans=0;
        for(int i=0;i<n;i++){

            if((i+1)<=(n-1)  && (a[i]=='1' && b[i]=='1'  && a[i+1]=='0' && b[i+1]=='0')){
                ans+=2;
                i++;
            }
            else if(((i+1)<=n-1) && (a[i]=='0' && b[i]=='0' && a[i+1]=='1' && b[i+1]=='1')){
                ans+=2;
                i++;
            }
            else if((a[i]=='0' && b[i]=='1')|| (a[i]=='1' && b[i]=='0')){
                ans+=2;
            }
            else if(a[i]=='0' && b[i]=='0'){
                ans++;
            }
        }
        cout<<ans<<"\n";
    }
}