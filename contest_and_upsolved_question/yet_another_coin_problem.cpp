#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
     ll n;
        cin>>n;
        ll coins=0;

        vector<int>a{1,3,6,10,15};
        int size=5;

        while(n){
            int idx= lower_bound(a.begin(),a.end(),n)-a.begin();
            cout<<"kya "<<idx<<"\n";

        if(idx==size){
            coins+=(n/a[4]);
            n=(n%a[4]);
            cout<<"1 "<<coins<<" 1 left "<<n<<"\n";
        }
        else if(a[idx]>n){
            coins+=(n/a[idx-1]);
            n=n%a[idx-1];
            cout<<"2 "<<coins<<" 2 left "<<n<<"\n";
        }
        else if(a[idx]==n){
            coins+=(n/a[idx]);
            n=n%a[idx];
            cout<<"3 "<<coins<<" 3 valeue left "<<n<<"\n";
        }
        }
        cout<<"sneha"<<coins<<"\n";

    }
}