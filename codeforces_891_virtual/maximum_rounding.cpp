#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        for(int k=(s.size()-1);k>=0;k--){
            cout<<k<<"\n";
            if((s[k]-'0')>=5){
                string a="1";
                int m= s.size()-k;
                cout<<m<<"\n";
                for(int i=1;i<=m;i++){
                    a=a+'0';
                }
                cout<<a<<"\n";
                long long int s_n=stoll(s);
               long long int a_n=stoll(a);
                cout<<s_n<<"\n";
                cout<<a_n<<"\n";
                s_n=s_n+a_n;
                cout<<s_n<<"\n";
                s= to_string(s_n);
                cout<<s<<"\n";
                bool flag=0;
                for(int j=k;j<=(s.size()-1);j++){
                    if(k==0){
                        flag=1;
                    }
                  else if(flag==1){
                        s[k+1]='0';
                    }
                    else if(flag==0){
                        s[k]='0';
                    }
                }
                cout<<s<<"\n";
            }
        }
        cout<<s<<"\n";
    }

}