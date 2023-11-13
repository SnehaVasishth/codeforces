#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,g;
        cin>>n>>k>>g;
        long long int dist= k *g;
        int m= n-1;
        int target= g/2;
        target--;
        long long int prof= m * target;
        long long int give=0,save=0,total=0;
        int r= target % g;
        if(r < g/2){
            give= (target-r) * m;
            save= prof - give;
            total += save;
            cout<<total<<"\n";
        }
        else if(r>= g/2){
            give= (target +(g -r)) * m;
            save= prof - give;
            total+=save;
            cout<<total<<"\n";
        }
        dist= dist- prof;
        target= dist;
        r= target %g;
        if(r < g/2){
            give= (target-r);
            save= dist- give;
            total += save;
            cout<<total<<"\n";
        }
        else if(r>= g/2){
            give= (target +(g -r)) ;
            save= dist - give;
            total+=save;
            cout<<total<<"\n";
        }
cout<<total<<"\n";
    }
}