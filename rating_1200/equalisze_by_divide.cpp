#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<ll>a(n);
     ll mini=1e9,newmini=1e9,j=-1,idx=-1,equal,cnt=0,maxlim=30*n;
     bool flag2=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(i==0){
            equal=a[i];
        }
        if(a[i]!=equal){
            flag2=1;
        }
        if(a[i]<mini){
            mini=a[i];
            j=i;
        }
    }
    if(flag2==0){
        cout<<0<<"\n";
    }

    else{
   
    vector<pair<int,int>>ans;
    bool flag=0;
    while(true){

        newmini=mini;
        idx=j;
        for(int i=0;i<n;i++){
            if(a[i]!=mini){
                if((a[i]%mini)!=0){
                    a[i]=(a[i]/mini)+1;
                    ans.push_back({i,j});
                }
                else if(a[i]%mini==0){
                    a[i]=(a[i]/mini);
                    ans.push_back({i,j});
                }
                cnt++;
            }
            if(a[i]<newmini){
                newmini=a[i];
                idx=i;
            }
        }
        mini=newmini;
        j=idx;
    flag=0;
        for(int i=1;i<n;i++){
            if(a[i]!=a[i-1]){
                flag=1;
                break;
            }
        }
        if(flag==0){
            break;
        }
        if(cnt>maxlim)
        break;

    }

    if(cnt<=maxlim && flag==0){
        cout<<cnt<<"\n";
        for(auto it:ans){
            cout<<(it.first+1)<<" "<<(it.second+1)<<"\n";
        }
        // for(int i=0;i<n;i++){
        //     cout<<a[i]<<" ";
        // }
        // cout<<"\n";
    }
    else{
        cout<<-1<<"\n";
    }
    }

}



}