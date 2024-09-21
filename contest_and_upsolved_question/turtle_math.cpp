#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
int t;
cin>>t;

while(t--){
    int n;
    cin>>n;
    vector<int>a(n);
    ll sum=0;
    set<int>st;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        st.insert(a[i]);
    }
    if(sum%3==0){
        cout<<0<<"\n";
    }
    else if(sum%3==2){
        cout<<1<<"\n";
    }
    else if(sum%3==1){
        ll rem= 1;
        bool flag=0;
        while(rem<=sum){
            if(st.find(rem)!=st.end()){
               flag=1;
                break;
            }
            rem+=3;

        }
        if(flag==1){
            cout<<1<<"\n";
        }
        else if(flag==0){
            cout<<2<<"\n";
        }

    }
}

}