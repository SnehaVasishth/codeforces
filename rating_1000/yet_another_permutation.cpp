#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        set<long long int>s;
        s.insert(1);
        vector<long long int>p;
        p.push_back(1);
        int i;
        bool flag=0,flag1=0;
        for(i=2;i<=n;i++){
            flag=0;
            for(int j=2;j*j<=i;j++){
                if(i%j==0){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
               
                flag1=0;
                for(int k=0;k<=n;k++){
                    long long int t= i*pow(2,k);
                   
                    if(t<=n){
                        s.insert(t);
                        p.push_back(t);
                    }
                  
                    if(p.size()>=n){
                        flag1=1;
                        break;
                    }
                      if(t>n){
                        break;
                    }
                }
            }
            if(flag1==1){
                break;
            }
        }
        bool flag2=0;
        for(int l=1;l<=n;l++){
            if(s.find(l)==s.end()){
                flag2=0;
                 for(int k=0;k<=n;k++){
                    long long int t= l*pow(2,k);
                   
                    if(t<=n){
                        s.insert(t);
                        p.push_back(t);
                    }
                  
                    if(p.size()>=n){
                        flag2=1;
                        break;
                    }
                      if(t>n){
                        break;
                    }
                }
               
            }
            if(p.size()>=n || flag2==1){
                break;
            }
        }
      for(auto it:p){
        cout<<it<<" ";
      }
      cout<<"\n";
    }
}