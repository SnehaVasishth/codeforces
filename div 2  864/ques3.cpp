#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int l,r;
        cin>>l>>r;
        int m,n,a,b;
        if((l==1 && r==3) || (l==2 && r==3)){
            cout<<-1<<"\n";
        }else{
             a=2;
            if(l>2){
             m= l-2;
            n=r-2;
            }
            for(int i=m;i<=n;i++){
                if(__gcd(2,i)!=1){
                    b=i;
                    break;
                }
            }
            cout<<a<<" "<<b<<"\n";
        }

    }
}