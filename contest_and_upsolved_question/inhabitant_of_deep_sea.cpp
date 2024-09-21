#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        vector<ll>a(n);
        for(ll i=0;i<n;i++)
        cin>>a[i];

ll i=0,j=n-1;
ll at1=k/2,at2=k/2;
if(k%2==1)
at1++;
bool flag=0;
ll cnt=0;
while(i<=j &&  (at1!=0 || at2!=0)){
if(i==j){
    if((at1+at2)>=a[i]){
        a[i]=0;
        cnt++;
        at1=0;
        at2=0;
        break;
    }
    else{
        break;
    }
}
    if(flag==0){
       
        //<<"attack sneha"<<at1<<"\n";
        if(a[i]<=at1)
        {
            // k=k-a[i];
           
            cnt++;
            at1=at1-a[i];
             
            i++;
            
            //<<" k sneha"<<k<<"cnt "<<cnt<<" i "<<i<<"\n";
        }
        else if(a[i]>at1){
            a[i]=a[i]-at1;
            // k=k-at1;
            at1=0;
            //<<"  asshi "<<a[i]<<"\n";
        }
        flag=1;
    }
    else if(flag==1){
        
        if(a[j]<=at2){
            // k=k-a[j];
          
            cnt++;
          
            at2=at2-a[j];
              j--;
            //<<" k  khushi"<<k<<" cnt "<<cnt<<" j "<<j<<"\n"; 
        }
        else if(a[j]>at2){
            a[j]=a[j]-at2;
            k=k-at2;
            at2=0;
            //<<" akank"<<a[j]<<"\n";
        }
        flag=0;
        
        
    }
    
}

cout<<cnt<<"\n";

    }
}