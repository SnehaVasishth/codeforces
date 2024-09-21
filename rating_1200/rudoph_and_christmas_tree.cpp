#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        double n,d,h;
        cin>>n>>d>>h;
        vector<double>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }

        double area=0;

        for(int i=1;i<n;i++){
            double x=a[i]-a[i-1];

            if(x>=h){
                area+=((d*h)/2);
            }
            else{
                double h1= x;
                double k= (h-h1)/h;
                double dtop= d*k;

                area+=((d+dtop)*(h1))/2;
            }
        }
        area+=((d*h)/2);
        cout<<setprecision(10);
        cout<<area<<"\n";
    }

}