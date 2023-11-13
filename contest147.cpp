#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,l,r,d,s,c=0,flag=0,by=0;
        cin>>n;
        vector<int> v(n);
        vector<int> a(n);
        vector<int> check;

        for(int i=1;i<=n;i++)
        {
            cin>>v[i];
        }

        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        
        for(int i=1;i<n;i++)
        {
            if(a[i]<=a[i+1])
            {
                check.push_back(i);
                v.push_back(a[i]);
                by=1;
            }
            else
            {
                if(by==0)
                continue;
                check.push_back(i);
                if(c<check.size())
                {
                    c=check.size();
                    d=*(check.begin());
                    s=*(check.end()-1);
                    flag=1;
                    check.clear();
                }
            }
            if(flag==0 && i==n-1)
            {
               check.push_back(n);
               d=*(check.begin());
               s=*(check.end()-1);
            }
        }
        cout<<d<<" "<<s<<endl;
    }
    return 0;
}