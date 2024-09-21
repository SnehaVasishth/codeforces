#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        stack<int>small;
        stack<int>large;
        vector<int>v;
        string res="";
        for(int i=0;i<n;i++){
            if(s[i]>=97 && s[i]<=122  && s[i]!='B' && s[i]!='b'){
                small.push(i);
            }
            else if(s[i]>=65 && s[i]<=90  && s[i]!='B' && s[i]!='b'){
                large.push(i);

            }
            else if(s[i]=='B'){
               if(large.empty()==false){
                int x= large.top();
               
                large.pop();
               
               }
            }
            else if(s[i]=='b'){
               if(small.empty()==false){
                int x= small.top();
               
                small.pop();
                
               }
            }

        }
        while(!small.empty()){
           int x=small.top();
           small.pop();
           v.push_back(x);
        }
          while(!large.empty()){
           int x=large.top();
           large.pop();
           v.push_back(x);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            res+=s[v[i]];
        }
        cout<<res<<"\n";
    }
}