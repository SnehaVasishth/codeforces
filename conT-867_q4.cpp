#include<bits/stdc++.h>
using namespace std;
vector<int> find_per(int n){
    vector<int>c(n);
    set<int>us;
    for(int i=0;i<n;++i){
        c[i]= i+1;
        us.insert(i+1);
    }
    for(int i=1;i<n;i++){
        int j=1;
        while(us.count((i+j)%n)>0){
            ++j;
    
        }
        c.insert(c.begin()+1,j);
        us.insert(j);
    }
    if(us.size()==n){
        return c;
    }
    else{
        return {-1};
    }
}
int main(){
    int t,m;
    cin>>t;
    while(t--){
cin>>m;
vector<int>super= find_per(m);
for(int j: super){
    cout<<j<<" ";
}
cout<<endl;
    }
}