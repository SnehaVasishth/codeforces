#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;

        ll maxpos= n*n,maxi=0;

        for(ll k=maxpos;k>=1;k--){
            ll sum=0;
            bool flag=0;
            ll cnt=0;
            vector<bool>visited(n+1,0);

            for(ll j=n;j>=1;j--){
                ll idx= k/j;
               if(idx==0){
                flag=1;
                break;
               }
               idx= (idx>n)?n:idx;
               cout<<"j kya hai  "<<j<<"  k kya hai "<<k<<"  idc=x  "<<idx<<'\n';
                if(visited[idx]==0){
                    visited[idx]=1;
                    sum+=(j*idx);
                    cnt++;
                    cout<<"sneha "<<sum<<"\n";

                }
                else if(visited[idx]==1){
                    while(visited[idx]==1 && (idx>=1)){
                        idx--;
                    }
                    if(idx>=1){
                        sum+=(j*idx);
                        visited[idx]=1;
                        cout<<"kanha  "<<sum<<"\n";
                       
                    }
                    else if(idx<1){
                        flag=1;
                        sum=-1;
                        cout<<"sparsh  "<<sum<<'\n';
                    }
                }
                
                if(flag==1){
                    cout<<"khushi \n";
                break;
                }
            }
            if(flag==1){
                break;
            }
        }
        cout<<maxi<<"\n";

    }
}