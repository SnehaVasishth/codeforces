#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            st.insert(x);
        }
        if(st.size()<3){
            cout<<((n/2)+1)<<"\n";
        }
        else if(st.size()>=3){
            cout<<n<<"\n";
        }
    }
}