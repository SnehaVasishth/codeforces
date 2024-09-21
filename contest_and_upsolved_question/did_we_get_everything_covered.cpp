#include<bits/stdc++.h>

using namespace std;
void subseq(string &s,int n,unordered_set<string>&ans,string op,int idx){
    if(n==0){
       ans.insert(op);
        return;
    }
    if(idx>=s.size()){
        return;
    }
    string inp=op;
    inp.push_back(s[idx]);
    subseq(s,n-1,ans,inp,idx+1);
    subseq(s,n,ans,op,idx+1);
    return;

}
int main(){
    int t;
    cin>>t;
    while(t--){

        int n,k;
        cin>>n>>k;
        string s;

        for(int i=0;i<n;i++){
            for(int i=0;i<k;i++){
                s+=('a'+i);
            }
        }
        unordered_set<string>ans;
        string op;
        subseq(s,n,ans,op,0);

        for(auto it:ans){
            cout<<it<<"\n";
        }

    }
}