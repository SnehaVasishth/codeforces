#include<bits/stdc++.h>
#define ll long long int
using namespace std;
int solve(){
    int n,k;
    cin>>n>>k;
    int mini=INT_MAX;
    int cnt=0;
    vector<int>a(n);
    int even=0,odd=0,c=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(a[i]==k){
            return 0;
        }
        if(a[i]%2==0){
            even++;
        }
     if(a[i]%2!=0){
            odd++;
        }
        if(a[i]==1){
            c++;
        }
    }
    if(k==2 && odd==n){
        return 1;
    }
    else if(k==2){
        return 0;
    }
    if(k==3){
        for(int i=0;i<n;i++){
            if(a[i]<=3){
                cnt=3-a[i];
                mini=min(mini,cnt);

            }
            else if(a[i]>3 &&a[i]<=6){
                cnt=6-a[i];
                mini=min(mini,cnt);
            }
            else if(a[i]>6 && a[i]<=9){
                cnt=9-a[i];
                mini=min(mini,cnt);
            }
         
        }
           return mini;
    }
        // if(k==4 && odd!=n){
        //     ll pro=1;
        //     for(int i=0;i<n;i++){
        //         pro*=a[i];

        //         if(pro%4==0){
        //             return 0;
        //         }
               
        //     }
           
        // }
        // if(k==4){
        //     if(c>=2){
        //         return 2;
        //     }
        // for(int i=0;i<n;i++){
        //     if(a[i]<=4){
        //         cnt=4-a[i];
        //         mini=min(mini,cnt);

        //     }
        //     else if(a[i]>4 &&a[i]<=8){
        //         cnt=8-a[i];
        //         mini=min(mini,cnt);
        //     }
           
            
        // }
        // return mini;
        // }
        
        if(k==5){
        for(int i=0;i<n;i++){
            if(a[i]<=5){
                cnt=5-a[i];
                mini=min(mini,cnt);

            }
            else if(a[i]>5 &&a[i]<=10){
                cnt=10-a[i];
                mini=min(mini,cnt);
            }
            
            
        }
        return mini;
        }
        return 0;
    
}
int main(){
    int t;
    cin>>t;
    while(t--){
       cout<<solve()<<"\n";
    }
}