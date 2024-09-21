#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n;
        cin>>s;
        vector<int>pre(n);
        vector<int>suff(n);
        unordered_set<char>st;
        for(int i=0;i<n;i++){
            st.insert(s[i]);
            pre[i]=st.size();
        }
        st.clear();
        for(int i=n-1;i>=0;i--){
            st.insert(s[i]);
            suff[i]=st.size();
        }
        int ans=INT_MIN;
        for(int i=0;i<n-1;i++){
            ans=max(ans,(pre[i]+suff[i+1]));
        }
        cout<<ans<<"\n";
    }
}