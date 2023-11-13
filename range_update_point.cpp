#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,q,l,r,x,d,rem,sum=0,d2;
        cin>>n>>q;

        int b[n];
        for(int i=0;i<n;i++)
        {
            cin>>b[i];
        }
        int f;
        cin>>f;

        for(int j=0;j<q;j++)
        {
        if(f==1)
        {
            cin>>l;
            cin>>r;
            sum=0;
            d=b[l];
            while(d)
            {
                rem=d%10;
                sum=sum+rem;
                d=d/10;
            }
            b[l]=sum;
            sum=0;
            d2=a[r];
            while(d)
            {
                rem=d%10;
                sum=sum+rem;
                d=d/10;
            }
            b[r]=sum;
        }
        else
        {
             cin>>x;
             cout<<b[x]<<endl;
        }
        }
    }
    return 0;
}