#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    vector<int>process(n),execution(n);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>process[i];
    }
    for(int i=0;i<n;i++){
        cin>>execution[i];
    }
    unordered_map<int,unordered_set<int>>mp1,mp2;
    unordered_set<int>st1,st2;
    for(int i=1;i<n;i++){
        st1.insert(process[i-1]);
        mp1[process[i]]=st1;
    }
    int cnt=0;
    for(int i=0;i<n;i++){
        if(i==0 && process[0]!=execution[0])
        cnt++;
        if(i>=1){
            st2.insert(execution[i-1]);
            mp2[execution[i]]=st2;
            for(auto it:mp1[execution[i]]){
                if(mp2[execution[i]].find(it)==mp2[execution[i]].end()){
                    cnt++;
                    break;
                }

            }
        }
    }
    cout<<cnt;
}