#include<bits/stdc++.h>

using namespace std;

bool solve(vector<int>&a){
    int n=a.size();
    int flag=0;
    if(n==1){
        return true;
    }
    if((a[1]-a[0])==2){
        a[0]++;

    }
    else if((a[1]-a[0])==1){
        flag=1;

    }
    else if((a[1]-a[0])==3){
        a[0]++;
        a[1]--;
    }
    else if((a[1]-a[0])>3){
        return false;
    }
    for(int i=2;i<n;i++){
        if((a[i]-a[i-1])==1){
            if(flag==1){
                flag=1;
            }
            continue;
        }
        else if((a[i]-a[i-1])==2){
            if(flag==1){
                a[i-1]++;
                flag=0;
            }
            else{
                a[i]--;
            }
        }
        else if((a[i]-a[i-1])==3 && flag==1){
            a[i]--;
            a[i-1]++;
            flag=0;
        }
        else if ((a[i]-a[i-1])>3  || ((a[i]-a[i-1])==3) && flag==0){
            return false;
        }
    }
    return true;



}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        bool ans=solve(a);
        (ans==0)?cout<<"NO\n":cout<<"YES\n";
    }
}