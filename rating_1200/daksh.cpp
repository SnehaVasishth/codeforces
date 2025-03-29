#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &a, int k) {
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(n + 1, INT_MAX)));

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= k; ++j) {
            for (int l = 0; l <= n; ++l) {
                if (j == 0) {
                    dp[i][j][l] = 0;
                } else if (i > 0) {
                    dp[i][j][l] = dp[i-1][j][l];
                    if (l == 0 || l == n) {
                        dp[i][j][l] = min(dp[i][j][l], (i > 0 ? dp[i-1][j-1][i] : INT_MAX));
                    } else {
                        int val = abs(a[i-1] - a[l-1]);
                        int res = (i > 0 ? dp[i-1][j-1][i] : INT_MAX);
                        if (res != INT_MAX) {
                            dp[i][j][l] = min(dp[i][j][l], val + res);
                        }
                    }
                }
            }
        }
    }

    int result = INT_MAX;
    for (int i = 0; i <= n; ++i) {
        result = min(result, dp[n][k][i]);
    }

    return result;
}

int main() {
    vector<int> a = {52,88,78,46,95,84,98,85,3};
    int n = a.size();
    int k = 3;
    cout << solve(n, a, k) << endl;
    return 0;
}