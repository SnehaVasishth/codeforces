#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        
        string s;
        cin>>s;
        int l =n/k;
        map<char,int>mp;
        for(int i=0;i<n;i++){
            
            mp[s[i]]++;
        }
        vector<int>v(n,-1);
        int pos=0;
        int i=0;
        for(auto it:mp){
            while(v[pos]!=-1){
                pos++;
            }
            i=pos;
            while(it.second!=0 && i<n){
                v[i]=(it.first-'a');
                i+=l;
                it.second--;
            }

        }
        for(int i=0;i<n;i++){
            if(v[i]==-1){
                for(auto it:mp){
                    if(it.second>0){
                        v[i]=it.first-'a';
                        it.second--;
                        break;
                    }
                }
            }
        }
        
        string res="";
        int f=0,g=0;
        for(f=0;f<n;f+=l){
            bool flag=0;
            for(g=0;g<l;g++){
                if(v[f+g]==(g)){
                    continue;
                }
                else{
                    flag=1;
                    char c= 'a'+g;
                    res+=c;
                    break;
                }
            }
            if(flag==0){
                char c= 'a'+g;
                res+=c;
            }
        }
        cout<<res<<"\n";


    }
}