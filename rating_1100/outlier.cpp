#include<bits/stdc++.h>

using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    int sum=0;
    unordered_set<int>st;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i];
        st.insert(a[i]);
    }
    int max_outlier=0;
    for(int i=0;i<n;i++){
        int total=sum-a[i];
        int original_sum=total/2;
        if(st.find(original_sum)!=st.end()){
        max_outlier=max(max_outlier,a[i]);
        }
    }
    cout<<max_outlier<<"\n";
}