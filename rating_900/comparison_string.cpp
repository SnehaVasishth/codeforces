#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        vector<int>v(n+1);
        if(s[0]=='<'){
            v[0]=1;
            v[1]=2;


        }
        
        else if(s[0]=='>'){
            v[0]= n+1;
            v[1]=n;
        }
        int i=1,j=2;

        while(i<n){
            
            if(s[i]=='<'){
                v[j]=v[j-1]+1;
                j++;
            }
            else if(s[i]=='>'){
                v[j]=v[j-1]-1;
                j++;
            }
            i++;

        }
       
        unordered_set<int>st;
        for(int i=0;i<=n;i++){
            st.insert(v[i]);
        }
        cout<<st.size()<<"\n";


    }
}