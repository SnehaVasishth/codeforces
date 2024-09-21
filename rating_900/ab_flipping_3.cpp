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
        int idx_a=-1,idx_b=-1;
        bool flag=0;
        for(int i=0;i<n;i++){
            if(s[i]=='A' && flag==0){
                idx_a=i;
                flag=1;

            }
            if(s[i]=='B'){
                idx_b=i;

            }
        }

        if((idx_b<idx_a)|| idx_b==-1 || idx_a==-1){
            cout<<0<<"\n";

        }
        else if(idx_a< idx_b){
            int cnt=0;
            vector<bool>v(n,true);
            for(int i=idx_a;i<=idx_b && i<=n-2;i++){
                if(s[i]=='A' && s[i+1]=='B' && v[i]==true){
                    swap(s[i],s[i+1]);
                    v[i]=false;
                    cnt++;

                }
            }

            for(int i=idx_b;i>=idx_a && i>=1;i--){
                if(s[i]=='B' && s[i-1]=='A' && v[i-1]==true){
                    swap(s[i],s[i-1]);
                    cnt++;
                    v[i-1]=false;
                }
            }
            cout<<cnt<<"\n";
        }
    }
}