#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,t,k,d;
    cin>>n>>t>>k>>d;
    int time1= ((float)t/k)*n;
   
   int time2=0;
        int t1=0;
    int t2=d;
    int n1=n;
    if(k>n){
        cout<<"NO"<<"\n";
    }
    else{
    while(n1!=0){
        t1=t+t1;
        n1=n1-k;
        if(n1==0){
            break;
        }
        if(t1>d){
            t2=t2+t;
            n1=n1-k;
        }
    }
    
    time2= max(t1,t2);
    
    if(time2<time1){
        cout<<"YES"<<"\n";
    }
    else{
        cout<<"NO"<<"\n";
    }
    }
}