#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int cnt=1,maxi=1;
        int flag=2;
        int el=s[0];


        for(int i=1;i<n;i++){
            if(s[i]==el){
                cnt++;
            }
            else{
                el=s[i];
                cnt=1;
            }
            maxi=max(maxi,cnt);
        }
        cout<<maxi+1<<"\n";
    }
}