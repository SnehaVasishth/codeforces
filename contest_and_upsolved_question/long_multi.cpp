#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string x,y;
        cin>>x>>y;
        int n=x.size();
        int i=0;
            while((x[i]==y[i]) && i<n){
                i++;
            }
        
            if((x[i]<y[i]) && i<n){
                swap(x,y);
            }
            i++;
            for(int j=i;j<n;j++){
                if(x[j]>y[j]){
                    swap(x[j],y[j]);
                }
            }
            cout<<x<<"\n";
            cout<<y<<"\n";
        

    }
}