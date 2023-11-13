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
        int k = 0;

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 2)
            {
                count++;
            }
        }
       

        if (count % 2 != 0)
            cout << -1 << "\n";

        else
        {

            for (k = 0; k < n - 1;)
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

                    k++;
                }
                else if (res1 == res2)
                {
                    cout << k + 1 << "\n";
                    break;
                }
            }
        }
    }
}
