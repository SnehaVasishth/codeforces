#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<pair<int,int>>res(n);
    vector<int>a(n),b(n);

    for(int i=0;i<n;i++){
        cin>>a[i];
    }
     for(int i=0;i<n;i++){
        cin>>b[i];
    }
    for(int i=0;i<n;i++){
        res[i]={a[i],b[i]};
    }

    sort(res.begin(),res.end());
    for(int i=0;i<n;i++){
        cout<<res[i].first<<" ";
    }
    cout<<"\n";
     for(int i=0;i<n;i++){
        cout<<res[i].second<<" ";
    }
    cout<<"\n";

}
}