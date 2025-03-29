#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();

       for(int i=1;i<n;i++){
        int j=i-1,curr=i;
        while(j>=0 && s[j]+1<s[curr]){
            s[curr]--;
            swap(s[curr],s[j]);
            curr--;
            j=curr-1;
        }
       }
       cout<<s<<"\n";
    }
}