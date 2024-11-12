#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string>a(2);
        for(int i=0;i<=1;i++){
            string str;
            cin>>str;
            a[i]=str;
        }
        int cnt=0;
        for(int i=0;i<=n-3;i++){
            if((i==0 || i==(n-3)) &&((a[0][i]=='x' && a[0][i+2]=='x' && a[1][i+1]=='.' && a[1][i]!='x' && a[1][i+2]!='x' && a[0][i+1]=='.') || (a[1][i]=='x' && a[1][i+2]=='x' && a[0][i+1]=='.' && a[0][i]!='x' && a[0][i+2]!='x' && a[1][i+1]=='.'))){
                cnt++;
            }
            if(i>0 && i<(n-3)){
                if(a[0][i]=='x' && a[0][i+2]=='x' && a[1][i+1]=='.' && a[0][i+1]=='.' && a[1][i]=='.' && a[1][i+2]=='.')
                cnt++;
                if(a[1][i]=='x' && a[1][i+2]=='x' && a[0][i+1]=='.' && a[1][i+1]=='.' && a[0][i]=='.' && a[0][i+2]=='.')
                cnt++;
            }
        }
        cout<<cnt<<"\n";
    }
}
