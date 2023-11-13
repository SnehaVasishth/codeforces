#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    int sum_a=0,sum_d=0;
    for(int i=0;i<str.size();i++){
        if(str[i]=='A'){
            sum_a++;
        }
         else if(str[i]=='D'){
            sum_d++;
        }
    }
    if(sum_a>sum_d){
        cout<<"Anton"<<"\n";
    }
    else if(sum_a<sum_d){
        cout<<"Danik"<<"\n";
    }
   else  if(sum_a==sum_d){
        cout<<"Friendship"<<"\n";
    }
}

