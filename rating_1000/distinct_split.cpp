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
        unordered_set<char>st1,st2;
        int j=-1;
        st1.insert(s[0]);
        for(int i=1;i<n;i++){
            if(st1.find(s[i])==st1.end()){
                st1.insert(s[i]);
            }
            else if(st1.find(s[i])!=st1.end()){
                j=i;
                break;
            }


        }
       if(j!=-1){
        for(j;j<n;j++){
            st2.insert(s[j]);
        }
       }
        
        cout<<(st1.size()+st2.size())<<"\n";
    }
}