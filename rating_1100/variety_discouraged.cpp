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
        vector<int>freq(n+1,0);
        for(int i=0;i<n;i++){
            cin>>a[i];
            freq[a[i]]++;
        }
        vector<int>len(n,0);
        if(freq[a[0]]==1)
        len[0]=1;

        for(int i=1;i<n;i++){
            if(freq[a[i]]==1){
                len[i]=len[i-1]+1;
            }
        }
        int maxi=0;
        maxi=*max_element(len.begin(),len.end());
        int l=-1,r=-1;
        if(maxi!=0){
        for(int i=0;i<n;i++){
            if(len[i]==maxi){
                l=i-maxi+2;
                r=i+1;
                break;
            }
        }
    }
        if(l==-1 && r==-1)
        cout<<0<<"\n";
        else{
            cout<<l<<" "<<r<<"\n";
        }
    }
}