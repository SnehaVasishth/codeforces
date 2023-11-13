#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        int count = 0;
        bool flag = 0;
        bool flag2=0;
        int k = (n-1)/2;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 2)
            {
                flag2=1;
                count++;
            }
        }
       

        if (count%2!=0&& count!=0)
            cout << -1 << "\n";

        else
        {

            while(k>=0 && k<=(n-2))
            {

                int res1 = 1;
                int res2 = 1;
                for (int i = 0; i <= k; i++)
                    res1 = res1 * a[i];
                for (int i = k + 1; i < n; i++)
                    res2 = res2 *a[i];
                if (res1 > res2)
                {
                    k--;
                }
                else if (res2 > res1)
                {
                    if(flag==1){
                        k++;
                        break;
                    }

                    k++;
                }
                else if (res1 == res2)
                {
                    if(k==0)
                break;
                else{
                    flag=1;
                    k--;
                }
                }
            }
        }
        if(k>=0&&k<=(n-2))
        cout<<k+1<<"\n";
        else
        cout<<-1<<"\n";
    }
}
