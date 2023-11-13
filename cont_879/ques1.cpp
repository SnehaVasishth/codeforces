#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        unordered_map<int,int>mp;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        int cnt=0;
        int sum= mp[1]+ mp[-1]*-1;
        while(mp[-1]%2!=0 || sum<0){
            int x=mp[1];
            int y= mp[-1];
            x++;
            y--;
            mp[1]=x;
            mp[-1]=y;
            sum= x+ y*-1;
            cnt++;
            if(mp[-1]%2==0 && sum>=0){
                break;
            }
        }
        cout<<cnt<<"\n";
    }
}