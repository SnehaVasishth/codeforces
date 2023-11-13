#include<bits/stdc++.h>


using namespace std;
int main(){
   long long int n;
   long long int x;
    cin>>n>>x;
     long long int sum=x;
   long long int dis=0;
    
    for(int i=0;i<n;i++){
        char s;
      long long int num;
        cin>>s>>num;
      
      
     
        if(s=='+'){
            sum+=num;
            
        }
        else if(s=='-'){
            if(sum>=num){
                sum-=num;
                

            }
            else{
                dis++;
            }
        }
    }
    cout<<sum<<" "<<dis<<"\n";
}