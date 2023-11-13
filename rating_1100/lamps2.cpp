#include<bits/stdc++.h>

using namespace std;
bool compartor(pair<long long int,long long int>&a,pair<long long int,long long int>&b){
  if(a.first !=b.first)
  return a.first<b.first;
  else
  return a.second>b.second;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<long long int,long long int>>v(n);
        for(long long int i=0;i<n;i++){
            cin>>v[i].first;
            cin>>v[i].second;
            
        }
        sort(v.begin(),v.end(),compartor);
       
       long long int x=0;
       long long  int cost=0;
       long long int prev= v[0].first;
        for(long long int i=0;i<n;i++){
           long long int curr= v[i].first;
            if(prev==curr){
                if(curr>x){
                    cost+=v[i].second;
                    x++;
                    prev=curr;

                }
            }
            else if(curr==prev && x>=curr){
                continue;
            }
            else if(curr!=prev){
                
                x=1;
                cost+=v[i].second;
                prev=curr;
            }
        }
        cout<<cost<<"\n";
    }
}