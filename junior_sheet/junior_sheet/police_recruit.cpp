#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
    }
    bool flag=0;
    int cnt=0;
    int sum=0;
    for(int i=0;i<n;i++){
        if(flag==0 && a[i]==-1){
            cnt++;
            

        }
        else if(a[i]>0){
            sum+=a[i];
            flag=1;
           
        }
        else if(flag==1 && sum>0 && a[i]==-1){
            sum--;
            
        }
        else if(flag==1 && sum<=0 && a[i]==-1){
            cnt++;
            
        }
    }
    cout<<cnt<<"\n";
}