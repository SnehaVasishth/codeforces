#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int count_a=1;
        int count_b=0;
for(int i=1;i<=n;){
    if(i<=n && (count_a+count_b<n)){
        i++;
        if(count_a+count_b+i>=n){
            count_b= n- count_a;
            break;
        }
        else{
            count_b+=i;
        }
    }
        else
        break;

        if(i<=n && (count_a+count_b<n)){
        i++;
        if(count_a+count_b+i>=n){
            count_b= n- count_a;
            break;
        }
        else{
            count_b+=i;
        }
    }
        else
        break;


        if(i<=n && (count_a+count_b<n)){
        i++;
        if(count_a+count_b+i>=n){
            count_a= n- count_b;
            break;
        }
        else{
            count_a+=i;
        }
    }
        else
        break;

        if(i<=n && (count_a+count_b<n)){
        i++;
        if(count_a+count_b+i>=n){
            count_a= n- count_b;
            break;
        }
        else{
            count_a+=i;
        }
    }
        else
        break;
    }
    cout<< count_a<<" "<<count_b<<"\n";
}

    }
