#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        int even=0;
        int odd=0;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            a[i]=x;
            if(x%2==0){
                even++;
            }
            else if(x%2!=0){
                odd++;
            }
        }
        if((even%2==0 && odd %2==0) || (even%2!=0 && odd %2==0)){
            cout<<"YES"<<"\n";
        }
        else if((even%2==0 && odd %2!=0) || (even %2!=0 && odd%2!=0)){
            cout<<"NO"<<"\n";
        }
    }
}