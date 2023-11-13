#include<bits/stdc++.h>
using namespace std;
int main(){
    string t;
    getline(cin,t);
    
    unordered_set<char>s;
    for(int i=0;i<t.size();i++){
        if(t[i]>=97 && t[i]<=122){
            s.insert(t[i]);

        }
    }
   
    cout<<s.size()<<"\n";
}
