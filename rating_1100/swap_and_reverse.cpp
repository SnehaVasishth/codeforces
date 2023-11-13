#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(k%2==0){
            sort(s.begin(),s.end());
         
        }
        else {
            string a="";
            string b="";
            
            int l=0,r=0;
            for(int i=0;i<n;i++){
                if(i&1){
                    b=b+s[i];
                }
                else{
                    a=a+s[i];
                }
            }
            sort(b.begin(),b.end());
            sort(a.begin(),a.end());
            for(int i=0;i<n;i++){
                if(i%2==0){
                    s[i]=a[l++];
                }
                else{
                    s[i]=b[r++];
                }
            }
          

        }
        cout<<s<<"\n";
    }
}