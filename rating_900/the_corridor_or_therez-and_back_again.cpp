#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            int x,y;
            cin>>x>>y;
            v.push_back({x,y});
            
        }
        sort(v.begin(),v.end());
        int first_trap=v[0].first;
        int first_trap_return_time=v[0].second+v[0].first-2;
        int current_time=v[0].first-1;
        int time_left_comeback= (first_trap_return_time-current_time)/2;
        int currentk=v[0].first+time_left_comeback;
        for(int i=1;i<n;i++){
            int trap=v[i].first;
           
            int trap_return_time=v[i].second-1+trap-1;
           
            current_time=v[i].first-1;
           
            time_left_comeback=(trap_return_time-current_time)/2;
            
            currentk=min(currentk,v[i].first+time_left_comeback);
           

        }
        cout<<currentk<<"\n";
    }

}