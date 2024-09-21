#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        char c;
        cin>>n>>c;
        string a;
        cin>>a;
        int i=0,j=n-1,k1=0,k2=n-1;
        if(c=='g'){
            cout<<0<<"\n";
        }
        else{
        while(a[i]!=c || a[j]!=c){
            if(a[i]!=c){
                i++;
            }
            if(a[j]!=c){
                j--;
            }
            // if(a[k1]!='g'){
            //     k1++;
            // }
            if(a[i]==c && a[j]==c){
                break;
            }

        }
        k1=0;
        while((a[k2]!='g') || (a[k1]!='g')){
            if(a[k2]!='g'){
                k2--;
            }
            if(a[k1]!='g'){
                k1++;
            }
            if(k2<k1){
                break;
            }
        }
       if(k1==k2 && (i==j)){
        (i<k1)?cout<<(k1-i):cout<<(n-i+k1);
       }
       else if(i==j && (k1<k2)&& (k2<i)){
        cout<<(n-i+k1);
       }
       else if(i==j && (k1>j)&& (k1<k2)){
        cout<<(k1-i);
       }
       else if((k1<i)&& (k2<j)&& (i<k2)){
        cout<<max(k2-i,n-j+k1);
       }
       else if((k1<i)&& (i<j)&&(j<k2)){
        cout<<(k2-i);
       }
       else if((i<k1)&&(k1<k2)&&(k2<j)){
        cout<<max(k1-i,n-j+k1);
       }
       else if((i<k1)&&(j<k2)){
        cout<<max(k1-i,k2-j);
       }
       else if((i<j)&&(k1<k2)){
        cout<<(k1-i);
       }
       else if((k1==k2)&& (i<j)&&(k1<i)){
        cout<<(n-i+k1);
       }
       else if((k1==k2)&&(i<j)&&(i<k1)&&(k1<j)){
        cout<<(n-j+k1);
       }
       else if(k1==k2 &&(i<j)&&(k1>j)){
        cout<<(k1-i);
       }
       cout<<"\n";
    }
}}