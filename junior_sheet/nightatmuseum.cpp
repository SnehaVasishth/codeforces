#include<bits/stdc++.h>

using namespace std;
int main(){
    string s;
    cin>>s;
    int cnt=0;
    int pos1,pos2;
    for(int i=0;i<s.size();i++){
        if(i==0){
            pos1=abs(s[i]-'a');
            pos2= abs(26-pos1);
            cnt+=min(pos1,pos2);
        }
        else{
            pos1= abs(s[i]-s[i-1]);
            pos2= abs(26-pos1);
            cnt+=min(pos1,pos2);
        }
    }
    cout<<cnt<<"\n";
}