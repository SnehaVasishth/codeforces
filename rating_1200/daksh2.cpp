#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &a, int k) {
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(n + 1, INT_MAX)));

    // Base Case: If k == 0, cost is 0
    for (int i = 0; i <= n; ++i) {
        for (int l = 0; l <= n; ++l) {
            dp[i][0][l] = 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int l = 0; l <= n; ++l) {
                // Not pick
                dp[i][j][l] = dp[i-1][j][l];

                // Pick
                if (l == 0 || l == n) {
                    dp[i][j][i] = min(dp[i][j][i], dp[i-1][j-1][0]);
                } else {
                    int val = abs(a[i-1] - a[l-1]);
                    if (dp[i-1][j-1][i] != INT_MAX) {
                        dp[i][j][i] = min(dp[i][j][i], val + dp[i-1][j-1][i]);
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