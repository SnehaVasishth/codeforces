#include<bits/stdc++.h>

using namespace std;
// bool same(string &s){
//     stack<char>st;
//     for(int i=0;i<s.size();i++){
//        if(st.empty()){
//         st.push(s[i]);
//        }
//        else if(st.top()=='(' && s[i]==')'){
//         st.pop();
//        }
//        else{
//         st.push(s[i]);
//        }
//     }
//     if(st.empty()==true){
        
//         return true;
//     }
//     else{
       
//         return false;
//     }
// }
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n= s.size();
        string t;
        
       
            if(s[0]=='(' && s[1]=='(' && n>2){
                for(int i=0;i<n;i++){
                    if(s[i]=='('){
                        t=t+'('+')';
                    }
                    if(s[i]==')'){
                        t=t+'('+')';
                    }
                }
            }

            else if(s[0]=='(' && s[1]==')' && n>2){
                for(int i=0;i<n;i++){
                    t=t+'(';
                }
                for(int i=0;i<n;i++){
                    t=t+')';
                }
            }
            else{
                
bool flag=0;
            for(int i=0;i<n-1;i++){
                if(s[i]==')' && s[i+1]=='('){
                    flag =1;
                    break;
                }

            }
            if(flag ==0){
                  for(int i=0;i<n;i++){
                    if(s[i]=='('){
                        t=t+'('+')';
                    }
                    if(s[i]==')'){
                        t=t+'('+')';
                    }
                }
            }
                else if(flag ==1){
                    for(int i=0;i<n;i++){
                    t=t+'(';
                }
                for(int i=0;i<n;i++){
                    t=t+')';
                }

                }

            }
            

        
        
       if(n==2 && s[0]=='(' && s[1]==')'){
        cout<<"NO"<<"\n";
       }
       else{
        cout<<"YES"<<"\n";
        cout<<t<<"\n";
       }
    }
}