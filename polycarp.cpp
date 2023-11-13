#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string inp;
        cin>>inp;
        string pie= "3141592653589793238462643383279";
        int count=0;
        for(int i=0;i<inp.size();i++){
            if(inp[i]== pie[i])
            count++;
            else
            break;
        }
        cout<<count<<"\n";
    }
}
