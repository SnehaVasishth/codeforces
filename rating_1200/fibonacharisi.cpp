#include<bits/stdc++.h>
#define ll long long

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        ll cnt=0;

        ll first,last,second;
        for(ll j=(n);j>=0;j--){
            last=n;
            first=j;
            // cout<<"last "<<last<<"first  "<<first<<"\n";
            bool flag=0;

            for(int i=k-2;i>=1;i--){
                second= last-first;
                // cout<<"kya i : "<<i<<"  second "<<second<<"\n";
                if((second>first)|| (second<0) || (first<0)){
                    flag=1;
                    break;
                }
                last=first;
                first=second;
                // cout<<" loopp last  "<<last<<"  firsdt  "<<first<<"\n";

            }
            if(flag==0){
                
                cnt++;
                // cout<<"cnt  "<<cnt<<"\n";
            }
        }

        cout<<cnt<<"\n";
    }
}