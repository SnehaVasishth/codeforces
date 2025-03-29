#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>weight(n);
        for(int i=0;i<n;i++){
            cin>>weight[i];
        }
        if(n==1){
            cout<<0<<"\n";
        }
        else{
            int maxi=0;
            int i=0,j=n-1;
            int sum1=weight[i];
            int sum2= weight[j];

            while(i<j){
                if(sum1<sum2){
                    i++;
                    sum1+=weight[i];
                }
                else if(sum1==sum2){
                    maxi=max(maxi,i+1+n-j);
                    i++;
                    sum1+=weight[i];
                }
                else if(sum1>sum2){
                    j--;
                    sum2+=weight[j];
                }
            }

            cout<<maxi<<"\n";
        }
    }
}