#include<bits/stdc++.h>

using namespace std;
int main(){
    int t;
    cin>>t;
   
    while(t--){
        int l,r;
        cin>>l>>r;
         int flag=0;
       
        if(l%2==0){
            int sec=l-2;
           if(sec>=1){
            flag=1;
            cout<<2<<" "<<sec<<"\n";
           }
        }
        if(r%2==0 && flag==0){
            int sec= r-2;
           if(sec>=1){
            flag=1;
            cout<<2<<" "<<sec<<"\n";
           }
        }
        else if(flag==0){
            int mid= (l+r)/2;
           
            if(mid%2==0){
                int sec=mid-2;
                if(sec>=1){
                    flag=1;
                cout<<2<<" "<<sec<<"\n";
                }
            }
            else{
                if((mid-1)>=l){
                    int first=mid-1;
                    int sec= first-2;
                    if(first>=1 && sec>=1){
                        flag=1;
                    cout<<2<<" "<<sec<<"\n";
                    }
                }
                 if((mid+1)<=r && flag==0){
                    int first=mid+1;
                    int sec= first-2;
                    if(sec>=1){
                        flag=1;
                    cout<<2<<" "<<sec<<"\n";
                    }
                }
                    else if(mid==l && mid==r){
                       int flag1=0;
                       int first;
                      
                       for(int i=2;i<=sqrt(mid);i++){
                        if(mid%i==0 && (mid-i)%i==0){
                            first=i;
                            flag=1;
                            flag1=1;
                            break;
                        }

                       }
                       if(flag1==1){
                        flag=1;
                        int sec= mid-first;
                        cout<<first<<" "<<sec<<"\n";
                       }
                      
                    
                }
            }
        }
        if (flag==0){
            cout<<-1<<"\n";
        }
    }
}
