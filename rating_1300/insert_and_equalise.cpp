#include<bits/stdc++.h>
#define ll long long
using namespace std;


bool binarysearch(ll m,int j,vector<ll>&a){
int i=0;

while(i<=j){
    ll mid= (i+j)/2;
    if(a[mid]==m){
        return true;
    }
    else if(a[mid]<m){
        i=mid+1;
    }
    else if(a[mid]>m){
        j=mid-1;
    }

}
return false;
}
int main(){
    int t;
    cin>>t;
    while(t--){
int n;
cin>>n;
vector<ll>a(n),v(n);
for(int i=0;i<n;i++){
    cin>>a[i];
}
sort(a.begin(),a.end());

v[0]=0;

for(int i=1;i<n;i++){
    v[i]=a[i]-a[i-1];
}

ll x=0;
for(int i=1;i<n;i++){
    x=__gcd(x,v[i]);
}
ll steps=0;
ll max_ele=a[n-1];
// cout<<"gcd  "<<x<<"\n";
// cout<<"max  "<<max_ele<<"\n";

if(x!=0){
for(int i=0;i<n;i++){
    ll diff= max_ele-a[i];
    steps+=(diff/x);

}

for(int i=1;i<=n;i++){
    ll m= max_ele-(x*i);
    //  cout<<"a[n+1] "<<m<<"\n";
    bool check=binarysearch(m,n-1,a);
    if(check==false){
       
        steps+=i;
        break;
    }
}
    
}
if(x==0 || n==1){
    cout<<n<<"\n";
}
else{
    cout<<steps<<"\n";
}

    }
}