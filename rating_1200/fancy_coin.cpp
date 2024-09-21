#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        ll m,k,a1,ak;
        cin>>m>>k>>a1>>ak;
        ll amt= a1+(k*ak);
        // cout<<"amt "<<amt<<"\n";
        ll fancy=0;
        if(a1>=m){
            // cout<<"sudh\n";
            fancy=0;
        }
        else if(amt>=m){
            if((ak*k)<m){
                // cout<<"arhc\n";
                ll left=(m-ak*k);
                fancy=0;
            }
                else if((ak*k)>=m){
                    ll coins= (m/k);
                    ll left= m-((m/k)*k);
                    if(left >a1){
                        //  cout<<"snhe \n";
                        fancy= (left-a1);
                    }
                    else{
                        //  cout<<"asq\n";
                        fancy=0;
                    }

                }
        }
                else if(amt<m){
                    ll y= m- (amt);
                    ll kfancy= y/k;
                    ll onefancy= y%k;
                    // cout<<onefancy<<"\n";
                    if(onefancy!=0){
                        ll mod= k-onefancy;
                        // cout<<"mode  "<<mod<<"\n";
                        if(mod<=a1){
                            // cout<<"kab\n";
                            fancy= (y+mod)/k;
                        }
                        else{
                            // cout<<"kanha\n";
                            fancy=kfancy+onefancy;
                        }
                    }
                    else{
                        // cout<<"khushi\n";
                        fancy=kfancy;
                    }

                }


        cout<<fancy<<"\n";

            
        
    }
}