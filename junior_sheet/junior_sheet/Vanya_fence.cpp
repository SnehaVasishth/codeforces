#include<bits/stdc++.h>

using namespace std;
int main(){
    int n,h;
    cin>>n>>h;
    vector<int>a(n);
    int sum=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
        if(a[i]<=h){
            sum++;
        }
        else if(a[i]>h){
            sum=sum+2;
        }

    }
    cout<<sum<<"\n";
}