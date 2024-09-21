#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>ans;
        int i=n,j=1;
        for(int m=0;m<n;){
            ans.push_back(i);
            if(i!=j){
                ans.push_back(j);
            }
            i--;
            j++;
            m+=2;
        }
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
}