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
       unordered_set<char>s1;
       unordered_set<char>s2;
       int maxi;
       s1.insert(s[0]);
       for(int j= 1;j< s.size();j++){
        s2.insert(s[j]);
       }
       int sum= s1.size()+ s2.size();
       for(int i=1;i<(n-1);i++){
         unordered_set<char>s3{0};
        s1.insert(s[i]);
        for(int j=i+1;j< s.size();j++){
           
            s3.insert(s[j]);
        }
        
        maxi= s1.size()+ s2.size();
        maxi= max(maxi,sum);
        sum= maxi;
       }
cout<<maxi<<"\n";

    }
}