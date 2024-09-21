#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
string a,b;
cin>>a>>b;
// vector<string>ans;
string c;
c+=a[0];
bool flag=0;
int idx=-1;

for(int i=0;i<=(n-2);){
    if( a[i+1]=='0' && b[i]=='1' && flag==0){
        c+='0';
        i++;
        if(i==(n-1)){
            c+=(b[i]);
            idx=i;
        }
    }
    else if( b[i]=='0' && a[i+1]=='1' && flag==0){
        c+='0';
        idx=i;
        flag=1;

    }
    else if( (b[i]=='1') && a[i+1]=='1' && flag==0){
      
        c+='1';
        // string d=c;
        // string e= b.substr(i+1);
        // d+=e;
        // cout<<"string:"<<d<<" i: "<<i<<"\n";
        
        i++;
         if(i==(n-1)){

            c+=(b[i]);
            idx=i;
        }
    }
    else if( b[i]=='0' && a[i+1]=='0' && flag==0){
        c+='0';
    // string d=c;
    // string e=b.substr(i+1);
    // d+=e;
    // cout<<"stringabc  :"<<d<<" i: "<<i<<"\n";
    

        i++;
         if(i==(n-1)){
            c+=(b[i]);
            idx=i;
        }

    }
    else if(flag==1){
        c+=(b[i+1]);

        i++;
    }
}

// for(auto it:ans){
//     cout<<"ans: "<<it<<"\n";
// }


// for(auto it:ans){
//     if(it==c){
//         cnt++;
//     }
// }



ll cnt=1;

for(int i=idx;i>=1;i--){
    if(a[i]==b[i-1]){
        cnt++;
    }
    else if(a[i]!=b[i-1]){
        break;
    }
}

cout<<c<<"\n";
cout<<cnt<<"\n";


    }
}