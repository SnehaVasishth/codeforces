#include<bits/stdc++.h>

using namespace std;
int main(){
    string a,b;
    cin>>a>>b;
    int n1=a.size();
    int n2=b.size();
    int ans;
    if(n1 != n2){
        ans=max(n1,n2);
    }
    if(n1==n2){
        if(a==b){
            ans=-1;
        }
        else{
            ans=n1;
        }
    }
    cout<<ans<<"\n";
}