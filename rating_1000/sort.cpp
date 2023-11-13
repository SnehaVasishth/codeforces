#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n;
        cin>>n;

        vector<pair<int,int>>khushi(n);
        vector<int> ladu(n);

        for(int i=0;i<n;i++)
        {   
            int x;
            cin>>x;
            khushi[i]={x,i};
        }
        
        sort(khushi.begin(),khushi.end());
        int j=n;
        for(int i=0;i<n;i++)
        {
            khushi[i].first=j;
            j--;
        }
        
        for(int i=0;i<n;i++)
        {
            ladu[khushi[i].second]=khushi[i].first;
        }
        for(int i=0;i<n;i++)
        {
            cout<<ladu[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}