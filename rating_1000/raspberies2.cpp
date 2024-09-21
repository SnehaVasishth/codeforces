#include<bits/stdc++.h>

using namespace std;
int solve(){
    int n,k;
    cin>>n>>k;
    int mini=INT_MAX;
    int cnt=0;
    int even=0,odd=0;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]%2==0){
            even++;
        }
        else{
            odd++;
        }


    }
    if(k!=4){
        bool flag=0;
        for(int i=0;i<n;i++){
            if(a[i]%k==0){
                flag=1;
            }
            else{
                int l= a[i]%k;
                cnt= k-l;
                mini=min(mini,cnt);
            }
        }
        if(flag==1){
            return 0;
        }
        else{
            return mini;
        }
    }
    else{
        bool flag=0;
        cnt=0;
        mini=INT_MAX;
        for(int i=0;i<n;i++){
            if(a[i]%k==0){
                flag=1;
            }
            else{
                int l= a[i]%k;
                cnt= k-l;
                mini=min(mini,cnt);
                
            }
        }
        if(flag==1 || even>=2){
            return 0;
        }
        else if(even==1){
            return 1;
        }
        else{
            return min(mini,2);

        }
    }
}
int main(){
    int t;
    cin>>t;
    while(t--){
        cout<<solve()<<"\n";
    }
}