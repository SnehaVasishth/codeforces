#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>b(n);
        vector<int>a(n);

        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            b[i]=x;
            a[i]=x;
        }
        cout<<n<<"\n";
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";


    }
}