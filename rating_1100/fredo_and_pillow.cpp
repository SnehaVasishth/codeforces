#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool solve(int pillow,int m,int k,int n){
    // cout<<"frodo"<<pillow<<"\n";
    int left=m-pillow;
    int i=k-1;
    int howmany=0;
    int pehle=pillow;
    while(i!=0){
        howmany=(pehle-1<=0)?1:pehle-1;
        // cout<<"hi "<<i<<"asshi "<<howmany<<"\n";
        if(howmany>left){
            return false;
        }
        else{
            left=left-howmany;
            i--;
            pehle=howmany;
        }
        // cout<<"left "<<left<<"\n";
        
    }
    i=k+1;
    pehle=pillow;
    howmany=0;
    while(i!=(n+1)){
        howmany=(pehle-1<=0)?1:pehle-1;
        // cout<<"byee "<<i<<"sneha "<<howmany<<"\n";
        if(howmany>left || left<=0){
            return false;
        }
        else{
            left=left-howmany;
            i++;
            pehle=howmany;
        }

        // cout<<"bacha "<<left<<"\n";

    }
    return true;
}
int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int low=1,high=m-(n-1);
    while(low<=high){
        int mid=(low+high)/2;
        if(solve(mid,m,k,n)){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    cout<<high<<"\n";

}