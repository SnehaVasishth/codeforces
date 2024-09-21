#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        s+=s;
        vector<int>green;
        for(int i=0;i<2*n;i++){
            if(s[i]=='g'){
                green.push_back(i);
            }
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            if(s[i]==c){
                int ub= lower_bound(green.begin(),green.end(),i)-green.begin();
                int ans= green[ub]-i;
                maxi=max(maxi,ans);
            }
        }
        cout<<maxi<<"\n";
    }
}