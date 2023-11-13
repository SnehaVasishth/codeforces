#include<bits/stdc++.h>

using namespace std;

bool compartor(pair<int,int>&a, pair<int,int>&b){
   
     if(a.first==b.first){
        if(a.second>b.second)
        return a>b;
        else
        return b>a;
    }

}
int main(){

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
           v[i].first=x;
           cin>>x;
           v[i].second=x;
           
        }
        sort(v.begin(),v.end(),compartor);
        multimap<int,int>mp;
        for(int i=0;i<n;i++){
            mp.insert({v[i].first,v[i].second});
        }
       for(auto it:mp){
        cout<<it.first<<" "<<it.second<<"\n";
       }
        long long int cost=0;
        long long int x=0;
        long long int y=0;
        for(auto it=mp.begin();it!=mp.end();it++){
            cout<<it->first<<"  "<<it->second<<"\n";
            cost+=it->second;
            x++;
            y=x;

            while(mp.find(x)!=mp.end()){
                mp.erase(x);
                cout<<"aashi\n";
                y--;
                
            }
            cout<<mp.size()<<"\n";
            for(auto &i:mp){
                cout<<i.first<<" "<<i.second<<"sneha\n";
            }
            x=y;
            if(y<0){
                x=0;
            }
        }
        cout<<cost<<"\n";
    }

}