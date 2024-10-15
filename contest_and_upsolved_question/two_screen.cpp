#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int q;
    cin>>q;
    while(q--){
        string s,t;
        cin>>s>>t;
        int n1=s.size();
        int n2=t.size();
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(s[i]==t[j]){
            i++;
            j++;
            }
            else{
                break;
            }

        }
        int ans=0;
        if(i==0){
            ans= (n1)+n2;
        }
        else
        ans=i+1+(n1-i)+(n2-j);
        cout<<ans<<"\n";
    }
}
