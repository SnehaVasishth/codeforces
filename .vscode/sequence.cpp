#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,count=1;
        cin>>n;

        vector<int> b(n);
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }

        ans.push_back(b[0]);
        for(int i=1;i<n;i++)
        {
            if(b[i]>=b[i-1])
            {
                ans.push_back(b[i]);
                count++;
            }
            else
            {
                ans.push_back(b[i]);
                ans.push_back(b[i]);
                count=count+2;
            }
        }
        cout<<count<<endl;
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}