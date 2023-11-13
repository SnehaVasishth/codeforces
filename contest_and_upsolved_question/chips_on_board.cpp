#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        vector<int>b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
         for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int m=n;
        long long int sum=0;
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        if(a[0]<=b[0]){
            int i=0;
            int j=0;
            while(m>0){
                sum=sum+a[i]+b[j];
                if(a[i+1]==a[i]){
                    i++;
                    j++;
                }
                else{
                    j++;
                }
                m--;
            }
        }
            else{
                  int i=0;
            int j=0;
            while(m>0){
                sum=sum+a[i]+b[j];
                if(b[j+1]==b[j]){
                    j++;
                }
                else{
                    i++;
                }
                m--;
            }

            }
        cout<<sum<<"\n";
    }
}