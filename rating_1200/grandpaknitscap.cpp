#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int mini=INT_MAX;
    int cnt=0;
    for(int i=0;i<26;i++){
        cnt=0;
        int l=0,k=n-1;
        while(l<k){
            if(s[l]==s[k]){
                l++;
                k--;
            }
            else if(s[l]!=s[k]){
                if(s[l]==('a'+i)){
                    l++;
                    cnt++;
                }
                else if(s[k]==('a'+i)){
                    k--;
                    cnt++;
                }
                else{
                    cnt=INT_MAX;
                    break;
                }
            }
        }
        mini=min(mini,cnt);

    }
    if(mini==INT_MAX)
    cout<<-1<<"\n";
    else
    cout<<mini<<"\n";
}
}