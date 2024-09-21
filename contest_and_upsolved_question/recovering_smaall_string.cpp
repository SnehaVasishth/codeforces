#include<bits/stdc++.h>

using namespace std;
int main(){
     int t;
     cin>>t;
     while(t--){
        int n;
        cin>>n;
        string t;
        char c='a';
        int m=n;
        if(m>=28){
            t=t+'z';
            m=m-26;
            if(m>=28){
                t=t+'z';
                m=m-26;
                c+=(m-1);
                t=c+t;
            }
            else if(m<28){
                m=m-1;
                c='a';
                c+=(m-1);
                t=c+t;
                t='a'+t;
            }
        }
        else if(m<28){
            m=m-2;
            c='a';
            c+=(m-1);
            t=t+c;
            t='a'+t;
            t='a'+t;

        }
        cout<<t<<"\n";
     }

}
   
