#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
       int n;
       cin>>n;
       unordered_map<int,queue<int>>mp;
       for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x].push(i);
       }
       vector<int>b(n,1);
       int flag=0;
       int z,y;
       for(auto i:mp){
        int x= i.first;
        if(mp[x].size()>=2 && flag==0){
            b[mp[x].front()]=1;
            mp[x].pop();
            b[mp[x].front()]=2;
            mp[x].pop();
            z=x;
            flag=1;

        }
         if(mp[x].size()>=2 && flag==1 && x!=z){
            b[mp[x].front()]=1;
            mp[x].pop();
            b[mp[x].front()]=3;
            mp[x].pop();
            y=x;
            flag=2;
            break;

        }
        
        
       }
       if(y==z)
       flag=3;

       if(flag==0||flag==1||flag==3){
        cout<<-1<<"\n";
       }
       else if(flag==2){
        for(auto i:b){
            cout<<i<<" ";
        }
        cout<<"\n";
       }

    }
}