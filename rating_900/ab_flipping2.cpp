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
        int cnt=0;
        vector<bool>v(n,0);
        while(true){
            bool flag=0;
            
            for(int i=1;i<n;i++){
                if(s[i]=='B' && s[i-1]=='A' && v[i-1]==0){
                    cnt++;
                    // cout<<"i: "<<i<<"->";
                    // cout<<"daksh baby "<<s<<"->";
                    swap(s[i],s[i-1]);
                    flag=1;
                    // cout<<"daksh ladu "<<s<<"\n";
                    v[i-1]=1;
                    break;
                }
            }
            
            if(flag==0){
                break;
            }
            
        }
        cout<<cnt<<"\n";
    }
}