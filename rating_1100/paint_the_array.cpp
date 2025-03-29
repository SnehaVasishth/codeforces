#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool check(vector<ll>&num,ll gcd1,bool flag){
    int idx;
    int n=num.size();
    if(flag==0){
        idx=0;
    }
    else{
        idx=1;
    }

    for(int i=idx;i<n;i+=2){
        if(num[i]%gcd1==0)
        return false;


    }
    return true;
}


int main(){
    int t;
    cin>>t;
    while(t--){
      
            int n;
            cin>>n;
            vector<ll>num(n);
            for(int i=0;i<n;i++){
                cin>>num[i];
            }

            ll gcd1=0,gcd2=0;

            for(int i=0;i<n;i++){
                if(i&1)
                gcd1=__gcd(gcd1,num[i]);
                else
                gcd2=__gcd(gcd2,num[i]);

            }

            bool ans1= check(num,gcd1,0);
            bool ans2= check(num,gcd2,1);

            if(ans1==true){
                cout<<gcd1<<"\n";
            }
            else if(ans2==true){
                cout<<gcd2<<"\n";
            }
            else{
                cout<<0<<"\n";
            }
        }
    }
