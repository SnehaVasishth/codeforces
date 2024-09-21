#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v;
        if(n%2==0){
           int i=0;
           cout<<"YES\n";
            while(i<n){
                v.push_back(-1);
                v.push_back(1);
                i+=2;
            }
            for(auto it:v){
                cout<<it<<" ";
            }
            cout<<"\n";
        }
        else if(n==1|| n==3){
            cout<<"NO\n";
        }
        else if(n%2!=0){
            cout<<"YES\n";
            int x= n/2;
            int y=n/2 -1;
            v.push_back(y);
            for(int j=1;j<n;){
                 v.push_back(-1*x);
                v.push_back(y);
               
                j+=2;
            }
            
            for(auto it:v){
                cout<<it<<" ";
            }
            cout<<"\n";
        }
    }
}