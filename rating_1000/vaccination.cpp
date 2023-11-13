#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,d,w;
        cin>>n>>k>>d>>w;
        vector<pair<int,int>>t(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            t[i].first=x;
            t[i].second=x+w;
        }
        int pack=0,m;
        for(int i=0;i<n;i++){
            int sneha=t[i].second;
            int last= sneha+d;
            int j=i;
            int m=k;
            while(t[j].first<=last && t[j].second>=sneha && m>0 && j<n){
                j++;
                m--;
            }
            pack++;
            i=j-1;
        }
        cout<<pack<<"\n";
    }
}