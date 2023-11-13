#include<bits/stdc++.h>
using namespace std;

pair<int,int> find(vector<int> a,vector<int> v)
{
    int n=a.size();
    int i=0;
    while(i<n && a[i]==v[i])
    i++;

    int j=n-1;
    while(j>=0 && a[j]==v[j])
    j--;

    if(i>j)
    return make_pair(1,n);

    int l=i,r=j;

    while(l>0 && a[l-1]==v[l-1])
    l--;

    while(r<n-1 && a[r+1]==v[r+1])
    r++;

    return make_pair(l+1,r+1);
}
int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<int> a(n),v(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<n;i++)
        cin>>v[i];

        auto result=find(a,v);
        cout<<result.first<<" "<<result.second<<endl;
    }
    return 0;
}