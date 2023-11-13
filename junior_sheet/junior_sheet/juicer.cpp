#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,b,d;
    cin>>n>>b>>d;
    vector<int>a(n);
    int juicer=0;
    int empti=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
       
    }
    for(int i=0;i<n;i++){
        if(a[i]<=b){
            juicer=juicer+a[i];
            
            if(juicer>d){
                juicer=0;
                empti++;
                
            }

        }
    }
    cout<<empti<<"\n";
}