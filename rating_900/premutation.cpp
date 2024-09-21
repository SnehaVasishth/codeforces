#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(n-1));
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            cin>>v[i][j];
        }
    }

    
    int el=v[0][0];
    int cnt=0;

    for(int i=0;i<n;i++){
        if(el==v[i][0]){
            cnt++;
        }
        else if(el!=v[i][0]){
            cnt--;
            if(cnt==0){
                el=v[i][0];
                cnt=1;
            }
        }

    }
    
    vector<int>res;
    for(int i=0;i<n;i++){
        if(v[i][0]!=el){
            
            res.push_back(el);
            for(int j=0;j<n-1;j++){
                res.push_back(v[i][j]);
            }
            break;

        }
    }
    for(auto it:res){
        cout<<it<<" ";
    }
    cout<<"\n";
}
}