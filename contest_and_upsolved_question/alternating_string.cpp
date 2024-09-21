#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        unordered_map<char,vector<int>>mp;
       int oper=0;

        if(n&1){
            unordered_map<char,int>mp1;
            for(int i=0;i<n;i++){
                mp1[s[i]]++;
            }
            bool flag=0;
            int maxim=1e9,idx=-1;
            for(int i=0;i<n;i++){
                if(mp1[s[i]]==1){
                    flag=1;
                    s.erase(i,1);
                    break;
                }
                if(mp1[s[i]]<maxim){
                    maxim=mp1[s[i]];
                    idx=i;

                }
            }
            if(flag==0){
                s.erase(idx,1);
            }
            oper++;
            n--;
        }
        for(int i=0;i<n;i++){
            mp[s[i]].push_back(i);
          
        }
        

        int odd_max=0,even_max=0;
        char odd_char,even_char;

        for(auto it:mp){
            int odd=0,even=0;
            for(auto i:it.second){
                if(i%2==0)even++;
                if(i%2!=0)odd++;
            }
            if(odd>odd_max){
                odd_max=odd;
                odd_char=it.first;
            }
            if(even>even_max){
                even_max=even;
                even_char=it.first;
            }
        }
        if(n&1){
            int num_even= (n/2)+1;
            int num_odd= (n/2);
            oper=oper+ (num_even-even_max)+(num_odd-odd_max);
        }
        else if((n&1)!=1){
            int num_even=(n/2);
            int num_odd=(n/2);
            oper=oper+(num_even-even_max)+(num_odd-odd_max);
        }
        cout<<oper<<"\n";
    }
}