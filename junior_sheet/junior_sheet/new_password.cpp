#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    for(int i=0, j=0;i<n;i++,j=(j+1)%k){
        char a= j+97;
        cout<<a;
    }

}