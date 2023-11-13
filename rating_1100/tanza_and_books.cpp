#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        vector<int>a(n);
        vector<int>b(n);
        vector<int>c(n);
        for(int i=n-1;i>=0;i--)
        cin>>a[i];
        for(int i=n-1;i>=0;i--)
        cin>>b[i];
        for(int i=n-1;i>=0;i--)
        cin>>c[i];
        bool flag=false;
        int temp=0;
        int curr=0;
        while(true){
            curr=0;
            if(a.size()){
                if((x|(a[a.size()-1]))==x){
                    temp=temp|a[a.size()-1];
                    a.pop_back();
                //  cout<<"what\n";
                    if(temp==x){
                        flag=true;
                        break;
                    }
                       curr++;
                }
            }
             if(c.size()){
                if((x|(c[c.size()-1]))==x){
                    temp=temp|c[c.size()-1];
                    c.pop_back();
                //  cout<<"kyu\n";
                    if(temp==x){
                        // cout<<"sneha\n";
                        flag=true;
                        break;
                    }
                       curr++;
                }
            }
             if(b.size()){
                if((x|(b[b.size()-1]))==x){
                    temp=temp|b[b.size()-1];
                    b.pop_back();
                // cout<<"kese\n";
                    if(temp==x){
                        // cout<<"aashi\n";
                        flag=true;
                        break;
                    }
                        curr++;
                }
            }
            if(curr==0){
                flag=0;
                break;
            }
        }
       if(x==0 || flag==1){
        cout<<"YES\n";
       }
       else{
        cout<<"NO\n";
       }

    }
}