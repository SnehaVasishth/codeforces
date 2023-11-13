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

        vector<int>aashi(n);
        vector<int> a(n);

        for(int i=0;i<n;i++)
        {
            cin>>aashi[i]>>a[i];
        }
        int kanha=INT_MAX;
        for(int i=0;i<n;i++)
        {
            int x=(a[i]-1)/2;
            kanha=min(kanha,x+aashi[i]);
        }
        cout<<kanha<<endl;
    }
    return 0;
}
