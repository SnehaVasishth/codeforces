#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int k;
    cin>>k;
    string s;
    cin>>s;
    vector<int>a;
    ll n=s.size();
    for(int i=0;i<s.size();i++){
        if(s[i]=='1'){
            a.push_back(i);
        }

    }
    if(a.size()<k){
        cout<<0<<"\n";
    }
    else if(k>=1){
        ll start=0,end=0,cnt=0;
        for(int i=0;(i+k-1)<a.size();i++){
            if(i==0){
                start=a[i]-0;

            }
            else if(i!=0){
                start=(a[i]-a[i-1]-1);
            }
            if((i+k)<=(a.size()-1)){
                end=(a[i+k]-a[i+k-1]-1);
            }
            else if((i+k)>=a.size()){
                end= (n-1-a[i+k-1]);
            }
            cnt+=(start+end+1+start*end);
        }
        cout<<cnt<<"\n";
    }
    else if(k==0){
        ll ans=0,start=0;
        if(a.size()==0){
            ans= (n*(n+1))/2;
            cout<<ans<<"\n";
        }
        else{
            ans=0;
            for(int i=0;i<a.size();i++){
                if(i==0){
                    start=a[i]-0;
                    ans+=((start*(start+1))/2);
                    
                }
                else if(i!=0){
                    start=a[i]-a[i-1]-1;
                    ans+=((start*(start+1))/2);
                   
                }
                 if(i==a.size()-1){
                    start= n-1-a[i];
                     ans+=((start*(start+1))/2);
                     
                     
                }
            }
            cout<<ans<<"\n";
        }

    }
}