#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int>& a, int k) {
    if (k > n) return -1; // If k > n, no valid subsequence exists

    // Initialize DP table
    vector<vector<int>> dp(n, vector<int>(k + 1, INT_MAX));

    // Base case: subsequence of length 1 has sum 0
    for (int i = 0; i < n; ++i) {
        dp[i][1] = 0;
    }

    // Precompute absolute differences
    vector<vector<int>> diff(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            diff[i][j] = abs(a[i] - a[j]);
        }
    }

    // Fill the DP table
    for (int j = 2; j <= k; ++j) { // Subsequence length
        vector<int> prefixMin(n, INT_MAX); // Prefix minimum array
        for (int i = j - 1; i < n; ++i) { // End index of subsequence
            if (i > 0) {
                prefixMin[i] = min(prefixMin[i - 1], dp[i - 1][j - 1] + diff[i][i - 1]);
            } else {
                prefixMin[i] = dp[i][j - 1];
            }
            dp[i][j] = prefixMin[i];
        }
    }

    // Find the minimum value among all subsequences of length k
    int ans = INT_MAX;
    for (int i = k - 1; i < n; ++i) {
        ans = min(ans, dp[i][k]);
    }

    return (ans == INT_MAX) ? -1 : ans;
}

int main() {
    // Test case 1
    vector<int> a1 = {96, 34, 48, 8, 72, 67, 90, 15, 85};
    int k1 = 5;
    cout << "Test case 1: " << solve(a1.size(), a1, k1) << endl;

    // Test case 2
    vector<int> a2 = {52, 88, 78, 46, 95, 84, 98, 55, 3};
    int k2 = 3;
    cout << "Test case 2: " << solve(a2.size(), a2, k2) << endl;

    // Test case 3
    vector<int> a3 = {1, 2, 3};
    int k3 = 2;
    cout << "Test case 3: " << solve(a3.size(), a3, k3) << endl;

    return 0;
}