#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    cin.ignore();
    while(t--){
        int n,m;
        cin>>n>>m;
        cin.ignore();
        vector<int>a(n);
        ll maxi=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i]>maxi)
            maxi=a[i];
        }
cin.ignore();
vector<int>ans;
        for(int i=0;i<m;i++){
            string s;
            getline(cin,s);
            stringstream ss(s);
            string token;
             getline(ss,token,' ');
             char ch= token[0];
           getline(ss,token,' ');
           int l=stoi(token);
           getline(ss,token,' ');
           int r=stoi(token);

           if(r< maxi || (l>maxi)){
            ans.push_back(maxi);
           }
           
           else if(l<=maxi && r>=maxi){
            if(ch=='+'){
                maxi++;
               ans.push_back(maxi);
            }
            else if(ch=='-'){
                maxi--;
                ans.push_back(maxi);
            }
           }


        }
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
}