#include<bits/stdc++.h>

using namespace std;
int main(){
    int k,r;
    cin>>k>>r;
    int i=1;
    long long int x;
    while(true){
        x= k*i;
        if(x%10==r || x%10==0){
            break;
        }
        i++;
    }
    cout<<i<<"\n";
}
