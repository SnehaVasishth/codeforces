#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
    int n,cnt=0;
    cin>>n;
     long long int ans=1;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int mini= *min_element(a.begin(),a.end());
   
    for(int i=0;i<n;i++){
        if(a[i]==mini && cnt==0)
        {
            cnt++;
            continue;
        }
        ans=ans*a[i];
    }
    mini++;
    ans=ans*mini;
    cout<<ans<<"\n";
    }
    return 0;
}