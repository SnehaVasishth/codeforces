#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll l,r;
        cin>>l>>r;
        ll first= log(l)/log(3);
        first++;
        double second= l+1;
        second= (l+1)*pow(3,first);       
        ll cnt=first;
        // cout<<cnt<<"\n";
        // cout<<second<<"\n";
        for(int i=1;i<(r-l+1);i++){
            if(i==1){
                double value= (log(second)/log(3));
                ll ajeeb= value+1;
                cnt+=ajeeb;
                //  cout<<" sneha "<<cnt<<"\n";
            }
            else{
                double num=l+i;
                double value=(log(num)/log(3));
                ll ajeeb=value+1;
                cnt=cnt+ajeeb;
                // cout<<num<<" asshi "<<cnt<<"\n";
            }            
        }
        cout<<cnt<<"\n";
        // ll aj= log(27.0)/log(3);
        // cout<<aj<<"\n";
    }
}