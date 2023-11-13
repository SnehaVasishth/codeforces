#include<bits/stdc++.h>
using namespace std;

int adding(int a[],int n,int i)
{
    int info=0;
    a[i]=-a[i];
    a[i+1]=-a[i+1];
    for(int j=0;j<n;j++)
    {
        info=info+a[j];
    }
    return info;
}

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        int n,sum=0,news=0;
        cin>>n;

        int a[n],b[n];
        for (int i=0;i<n;i++)
        {
            cin>>a[i];
            sum=sum+a[i];
        }

        for(int i=0;i<n-1;i++)
        {
            for(int j=0;j<n;j++)
            {
                b[j]=a[j];
            }
            news=adding(b,n,i);
            if(sum<news)
            {
            sum=news;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}