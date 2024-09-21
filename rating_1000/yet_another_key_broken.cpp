#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        vector<bool>v(n,true);
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]=='B'){
                v[i]=false;
                j=i-1;
                while((s[j]>=97 && s[j]<=122) || (s[j]=='B') || (s[j]=='b') || (s[j]>=65 && s[j]<=90 && v[j]==false)&& j>=0){
                    j--;

                }
                if(j>=0){
                    v[j]=false;
                }
            }
            if(s[i]=='b'){
                v[i]=false;
                j=i-1;
                while((s[j]>=65 && s[j]<=90) || (s[j]=='B') || (s[j]=='b') || (s[j]>=97 && s[j]<=122 && v[j]==false)&& j>=0){
                    j--;

                }
                if(j>=0){
                    v[j]=false;
                }

            }
        }
        string res="";
        for(int i=0;i<n;i++){
            if(v[i]==true){
                res+=s[i];
            }
        }
        cout<<res<<"\n";
    }
}