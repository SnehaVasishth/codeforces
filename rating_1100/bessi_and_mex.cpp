#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int minmex=0,maxmex=1;
    unordered_set<int>st;
    vector<int>res(n);
    for(int i=0;i<n;i++){
        if(st.count(minmex-a[i]) || (minmex-a[i])<0 || (minmex-a[i])>n){
            res[i]=maxmex-a[i];
        }
        else{
            res[i]=minmex-a[i];
        }

        if(res[i]==minmex){
            minmex=maxmex;
            maxmex++;
            while(st.count(maxmex)){
                maxmex++;
            }
        }
        else if(res[i]==maxmex){
            maxmex++;
            while(st.count(maxmex)){
                maxmex++;
            }
        }
        st.insert(res[i]);
    }
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
    cout<<"\n";
}
}