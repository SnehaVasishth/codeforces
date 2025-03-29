#include<bits/stdc++.h>

using namespace std;
#define ll long long

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();

        int i=0;

        int start_zero=0,length_zero=0,length_one=0;

        while(i<n && s[i]!='0'){
            i++;
        }

        int l1=1,r1=n,l2=-1,r2=-1;
        if(i==n){
            l2=1;
            r2=1;

        }
        else{

             start_zero=i;

            while(i<n && s[i]!='1'){
                i++;
            }

            length_zero=i-start_zero;
            length_one=start_zero;

            int start_pos= min(length_zero,length_one);

            l2= start_zero-start_pos;

            r2= l2+n-start_zero-1;

            l2++;
            r2++;


            
        }

        cout<<l1<<" "<<r1<<" "<<l2<<" "<<r2<<"\n";
    }
}