#include<bits/stdc++.h>
using namespace std;

int transformString(string s){
    vector<int>count(26,0);

    for(char c:s){
        count[c-'a']++;
    }
    int odd=0;
    for(int i=0;i<26;i++){
        if(count[i]%2!=0){
            odd++;
        }
    }
    if(odd<=1)
    return 0;
    return (odd-1);
}
int main(){
    string s;
    cin>>s;
    int ans= transformString(s);
}