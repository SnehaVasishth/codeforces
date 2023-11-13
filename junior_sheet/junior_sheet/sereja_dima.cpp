#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        a[i]=x;
    }
    int flag_s=-1,flag_d=0;
    int ser=0,dim=0;
    int i=0;
    int j=n-1;
    while(i<=j){
        if(a[i]>=a[j]){
            if(flag_s==-1){
                ser+=a[i];
                flag_s=0;
                flag_d=-1;
                i++;

            }
            else{
                dim+=a[i];
                flag_s=-1;
                flag_d=0;
                i++;

            }
        }
        else if(a[i]<a[j]){
            if(flag_s==-1){
                ser+=a[j];
                flag_s=0;
                flag_d=-1;
                j--;

            }
            else{
                dim+=a[j];
                flag_s=-1;
                flag_d=0;
                j--;

            }
        }
    }
    cout<<ser<<" "<<dim<<"\n";
}