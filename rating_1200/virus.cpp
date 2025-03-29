#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>infect(m);
        for(int i=0;i<m;i++){
            cin>>infect[i];
        }
        vector<pair<int,pair<int,int>>>info;
        sort(infect.begin(),infect.end());
        for(int i=1;i<m;i++){
            info.push_back({infect[i]-infect[i-1]-1,{infect[i-1],infect[i]}});
        }
        if((n-infect[m-1]+infect[0]-1)>0){
            // cout<<n-infect[m-1]+infect[0]-1<<endl;
            info.push_back({(n-infect[m-1]+infect[0]-1),{infect[0],infect[m-1]}});
        }
        sort(info.begin(),info.end(),greater<pair<int,pair<int,int>>>());

        int day=2;
        int k=info.size();
        int protect=0;
        
        for(int i=0;i<k;i++){
            // cout<<info[i].first<<" "<<info[i].second.first<<" "<<info[i].second.second<<"\n";
            int live= (info[i].first-((day-2)*2));
            if(live==1 || live==2){
                protect++;
            }
            else if(live>2){
                protect+=(live-1);
            }
            day+=2;

        }

        cout<< n-protect<<"\n";

        

    }
}