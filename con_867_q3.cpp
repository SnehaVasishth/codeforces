#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;

    while(t--)
    {
        long long int m,sol;
        cin>>m;

        sol=m*4+m-1;
        m=m-1;
        while(m>2)
        {
            m=m-1;

            sol=sol+m*2;
        }

        sol=sol+3;

        cout<<sol<<endl;
    }
    return 0;
}