#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m=2*n;
        vector<int>v(m);
        for(int i=0;i<m;i++){
            cin>>v[i];
        }

        sort(v.begin(),v.end());
        long long int dist=0;

        int i=1;
        int j= n+1;
        for(i,j;i<n && j<m;i++,j++){

            dist+= abs(v[i]-v[i-1])+abs(v[j]-v[j-1]);


        }
        cout<<dist<<"\n";
        cout<<v[0]<<" "<<v[n]<<"\n";
        i=1;
        j=n+1;
        for(i,j;i<n && j<m;i++,j++){
            cout<<v[i]<<" "<<v[j]<<"\n";
            
        }
    }
}