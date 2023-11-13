#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int>a(n);
    int cnt1=0;
    int cnt2=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    bool flag=0;
    for(int i=0;i<n;i++){
        if(a[i]==0){
            flag=1;
            cnt1++;
        }
        else if(flag==0){
            continue;


        }
        else if(flag==1){
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(a[i]==0){
            cnt2++;
        }
        else if(a[i]==1){
            if(cnt2>cnt1){
                cnt1=cnt2;
            }
            cnt2=0;
        }
        else if(cnt2>cnt1){
            cnt1= cnt2;
        }
    }
    cout<<cnt1<<"\n";
    }
}