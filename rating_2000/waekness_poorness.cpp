#include<bits/stdc++.h>
#define ll long long
using namespace std;
double fun(double x,vector<ll>&a){
double max1=0,max2=0,sum=0;
int n=a.size();
for(int i=0;i<n;i++){
    sum+=(a[i]-x);
    if(sum<=0){
        sum=0;
    }
    max1=max(max1,sum);


}
sum=0;
for(int i=0;i<n;i++){
    sum+=(x-a[i]);
    if(sum<=0){
        sum=0;
    }
    max2=max(max2,sum);
    

}
return (max(max1,max2));
}
int main(){
    ll n;
    cin>>n;
    vector<ll>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    double l=-100000;
    double r=100000;
    while(r-l>0.0000000000000001){
        double m1=l+(r-l)/3;
        double m2= r-(r-l)/3;
        double fm1= fun(m1,a);
        double fm2=fun(m2,a);
        if(fm1<fm2){
           r=m2;
        }
        else if(fm1>fm2){
          l=m1;
        }
        else{
            l=m1;
            r=m2;
        }
    }
    cout<<std::setprecision(15)<<fun(r,a)<<"\n";
}