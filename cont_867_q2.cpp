#include<bits/stdc++.h>
using namespace std;

long long int max(vector<long long int> v)
{
    long long int max=v[0];

    long long int sol=0;
    for(long long int i=1;i<v.size();i++)
    {
        if(max<v[i])
        {
            max=v[i];

            sol=i;
        }
    }

    return sol;
}

long long int min(vector<long long int> v)
{
    long long int min=v[0];

    long long int sol=0;
    for(long long int i=1;i<v.size();i++)
    {
        if(min>v[i])
        {
            min=v[i];

            sol=i;

        }
    }
    return sol;
}
int main()
{
    long long int t;
    cin>>t;

    while(t--)
    {
        long long int n,q=2,in,inn,x,y,c,b;
        cin>>n;
        vector<long long int> z(n);
        vector<long long int> :: iterator it;
        for(long long int i=0;i<n;i++)
        {
            cin>>z[i];
        }

        if(n==2)
        {
            cout<<z[0]* z[1]<<endl;
        }

        else
        {
        in=max(z);
        x=z[in];
        it=z.begin()+in;
        z.erase(it);

        inn=max(z);
        y=z[inn];

        in=min(z);
        c=z[in];
        it=z.begin()+in;
        z.erase(it);

        inn=min(z);
        b=z[inn];

        if(c*b>x*y)

        cout<<c*b<<endl;

        else
        cout<<x*y<<endl;
        }
    }
    return 0;
}