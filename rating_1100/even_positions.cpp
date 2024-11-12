#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        stack<pair<char,int>>st;
        st.push({'(',0});
        int ans=0;
        for(int i=1;i<n;i++){
            // cout<<" value i"<<i<<"  "<<s[i]<<"\n";
            if((st.empty()==false )&&((s[i]==')') || (s[i]=='_'))){
                int num= st.top().second;
                ans+=(i-num);
                // cout<<num<<" "<<(i-num)<<"\n";
                st.pop();
            }
            else if(s[i]=='('){
                // cout<<" aashi\n";
                st.push({'(',i});
            }
            else if((st.empty()==true) && (s[i]=='_')){
                st.push({'(',i});
                // cout<<"sneha\n";
            }
        }
        cout<<ans<<"\n";
    }
}