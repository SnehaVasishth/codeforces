#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {

        int n,res=0,c=0;
        
        cin>>n;

        vector<int> sneha(n);

        for(int i=0;i<n;i++)
        {
            cin>>sneha[i];
        }

        for(int i=0;i<n;i++)
        {
            if(sneha[i]==0)
            {
                c++;
            }
            else
            {
                if(c>res)
                {
                    res=c;
                }
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}