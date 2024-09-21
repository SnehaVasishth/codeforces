#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool possible(vector<int>&a,vector<int>&b,int cooky,int magic){
    for(int i=0;i<a.size();i++){
        ll in= a[i]*cooky;
        if(in>b[i]){
            ll req=in-b[i];
            if(req>magic){
                return false;
            }
            else if(req<=magic && magic!=0){
                magic-=req;
            }
            else if(magic==0){
                return false;
            }
        }

    }
    return true;

}
int main(){
    int n,k;
    cin>>n>>k;
    vector<int>a(n),b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    int low=1;
    int high= *min_element(b.begin(),b.end())+k;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(possible(a,b,mid,k)){
            low=mid+1;
        }
        else {
            high=mid-1;
        }
    }
    cout<<high<<"\n";
}