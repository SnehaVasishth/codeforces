#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>a(n);
       set<ll>st;
ll sum=0;
bool flag=0;

        for(int i=0;i<n;i++){
            cin>>a[i];
            if(i%2==0){
                a[i]=-a[i];
            }
            sum+=a[i];
            if(st.find(sum)!=st.end() || sum==0){
                flag=1;
               

            }
            else{
                st.insert(sum);
            }
        }
        
        
        if(flag==1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
}