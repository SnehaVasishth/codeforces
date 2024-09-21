#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a,b;
        cin>>n>>a>>b;
        int k=1, l=n;
    vector<int>v(n,0);
    v[0]=a;
    v[n-1]=b;
    int mini=a,maxi=b;
    for(int i=1;i<n/2;i++){
        if(l!=b && l!=a){
            v[i]=l;
            l--;
        }
        else if(l==b){
            l--;
            l= (l==a)?(l-1):l;
            v[i]=l;
            l--;
        }
        else if(l==a){
            l--;
            l= (l==b)?(l-1):l;
            v[i]=l;
            l--;

        }
        if(mini>v[i]){
            mini=v[i];
        }
    }
    for(int i=n/2;i<=n-2;i++){
        if(k!=a && k!=b){
            v[i]=k;
            k++;
        }
        else if(k==b){
            k++;
            k= (k==a)?k+1:k;
            v[i]=k;
            k++;
        }
        else if(k==a){
            k++;
            k= (k==b)?k+1:k;
            v[i]=k;
            k++;
        }
        if(maxi < v[i]){
            maxi=v[i];
        }
    }
    if(mini!=a || maxi!=b){
        cout<<-1<<"\n";
    }
    else{
        for(auto c:v){
            cout<<c<<" ";
        }
        cout<<"\n";
    }

    }
}