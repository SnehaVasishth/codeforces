#include<bits/stdc++.h>
#define ll long long
using namespace std;


// void solve(ll no_stud,ll howmany){
//     int j=1;
//     int cnt=0;
//     for(int k=1;k<=no_stud;k++){
//         for(int i=1;i<=howmany;i++){
//             cout<<j<<" ";
//             cnt++;
//         }
//         j=cnt+2;

//     }
//     cout<<"\n";
// }


void sol(ll stud1,ll how1,ll stud2,ll how2){
    int j=1;
    int cnt=0;
    int i=1;
    for(i;i<=stud1;i++){
                    for(int k=1;k<=how1;k++){
                        cout<<j<<" ";
                        cnt++;

                    }
                    j=cnt+2;
                }
                j=cnt+1;
                for(i=1;i<=stud2;i++){
                    for(int k=1;k<=how2;k++){
                        cout<<j<<" ";
                        cnt++;
                    }
                    j=cnt+2;
                }
                cout<<"\n";

}

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,x,y;
        cin>>n>>x>>y;
        if((x==0 && y==0) || (x==y)){
            cout<<-1<<"\n";
        }
        // else if(x==y && x!=0){
        //     ll z= ((n-1)/x);
        //     if((z*x)==n-1 && (z<n)){
        //         solve(z,x);
        //     }
        //     else{
        //         cout<<-1<<"\n";
        //     }
        // }
        else{
            
        ll a= ((n*y-n+1)/(y-x));
        ll b= ((n-1-x*n)/(y-x));
        if((a*(y-x))==(n*y-n+1) && (b*(y-x))==(n-1-x*n)){
            if(a>n || b>n || a<=0 || b<=0){
                cout<<-1<<"\n";
            }
            else if((a+b)==n){

                sol(a,x,b,y);
                
            }
        }
        else{
            cout<<-1<<"\n";
        }
        }

    }
}