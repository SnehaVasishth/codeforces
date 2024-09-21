#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string x,y;
        cin>>x>>y;

        int i=0;
        bool flag=0;
        int n=x.size();
        while(i<n){

            if(x[i]>y[i]){
                flag=0;
                break;
            }
            else if(x[i]<y[i]){
                flag=1;
                break;
            }
            i++;

        }
        i++;

        for(int j=i;j<n;j++){
            if()
        }

    }
}