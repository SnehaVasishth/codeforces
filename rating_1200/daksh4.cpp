#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &a, int k) {
    if (k > n) return -1; // If k is greater than n, no subsequence of length k exists

    // Initialize DP table
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, INT_MAX));

    // Base case: subsequence of length 0 has special value 0
    for (int i = 0; i <= n; ++i) {
        dp[0][i] = 0;
    }

    // Fill the DP table
    for (int i = 1; i <= k; ++i) {
        for (int j = 1; j <= n; ++j) {
            // Option 1: Do not pick the j-th element
            dp[i][j] = dp[i][j - 1];

            // Option 2: Pick the j-th element
            if (i == 1) {
                dp[i][j] = min(dp[i][j], a[j - 1] / 2);
            } else if (i == 2) {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[j - 1] / 2) - (a[j - 1] / 2));
            } else {
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + (a[j - 1] / 2));
            }
        }
    }

    // The answer is the minimum value in the last row
    int result = dp[k][n];
    return result == INT_MAX ? -1 : result;
}

int main() {
    // Example usage

    vector<int> a = {52, 88, 78, 46, 95, 84, 98, 55, 3};
    int n=a.size();
    int k = 3;

    int result = solve(n, a, k);
    cout << "Minimum special value: " << result << endl;

    return 0;
}