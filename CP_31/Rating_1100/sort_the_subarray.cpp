#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<ll>a1(n),a2(n);
        for(int i=0;i<n;i++){
            cin>>a1[i];
        }
          for(int i=0;i<n;i++){
            cin>>a2[i];
        }
        int l=0,r=0,diff=0,maxi=0;
        int i=0,j=1;
        while(j<n){
            bool flag=0;
            while(i<n && j<n && (a2[j-1]<=a2[j])){
                diff=(j-i+1);
                // if(a1[j-1]>a1[j]){
                // if(maxi<=diff){
                //     maxi=diff;
                //     l=i;
                //     r=j;
                // }
                j++;
                flag=1;
            }

            j--;
            
            for(int k=i;k<=(j-1) && flag==1;k++){
                if(a1[k]>a1[k+1]){
                    if(maxi<=diff){
                        maxi=diff;
                        l=i;
                        r=j;
                    }
                }

            }
            j++;
            
            i=j;
            j++;
        }
        l++;
        r++;
        cout<<l<<" "<<r<<"\n";
    }
}