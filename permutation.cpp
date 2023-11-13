#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<vector<int>> v(n,vector<int>(n-1));
        vector<int>v1(n);
        unordered_map<int,int>occur;
        for(int i=0;i<n;i++){
            for(int j=0;j<(n-1);j++)
            cin>> v[i][j];
        }
        for(int i=0;i<n;i++)

        occur[v[i][0]]++;

        int maxi= occur.begin()->second;



        v1[0]= occur.begin()->first;

        for(auto it:occur){

            if(it.second>maxi){
                v1[0]=it.first;
                maxi= it.second;
            }
        }
        for(int i=0;i<n;i++){
            if(v[i][0] !=v1[0]){
                for(int j=0;j<(n-1);j++){

                    v1[j+1]= v[i][j];
                }
                break;
            }
        }

        for(int i=0;i<n;i++){
            cout<< v1[i]<<" ";
           
        }
         cout<<endl;
    }
}