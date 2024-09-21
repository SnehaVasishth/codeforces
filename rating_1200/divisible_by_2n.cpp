#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll solve(int n){
    ll cnt=0;
    while(true){
        int num= n/2;
        if((num*2)==n){
            cnt++;
            n=n/2;
        }
        else{
            return cnt;
        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
    int n;
    cin>>n;
    vector<int>a(n+1);
    ll even=0,cnt=0;
    vector<ll>v;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]%2==0){
            even+=solve(a[i]);
           

        }
         if(i%2==0){
            
            ll num= solve(i);
            cnt+=num;
            v.push_back(num);
            
        }
    }
    sort(v.begin(),v.end(),greater<int>());
   
    if((n-even)<=cnt  && n>even){
        int k=0;
        int req= n-even;
        for(auto it:v){
            if(req==0){
                break;
            }
            if(it>=req){
                k++;
                break;
            }
            else{
                req-=it;
                k++;
            }
        }
        cout<<k<<"\n";
    }
    else if(even>=n){
        cout<<0<<"\n";
    }
    else if((n-even)>cnt){
        cout<<-1<<"\n";
    }

}
}

