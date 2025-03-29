#include <bits/stdc++.h>
using namespace std;

long long solve(int n, vector<int> a, int k) {
    // Initializing the DP table with INT_MAX
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(n + 2, INT_MAX)));

    // Base case: If no elements are taken, the cost is 0
    for (int j = 0; j <= k; j++) {
        dp[0][j][0] = 0;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 0; l < i; l++) {  // Ensuring l starts from 0
                int notpick = dp[i - 1][j][l];  // Case where we do not take the current element
                int pick = INT_MAX;

                if (l == 0) {
                    pick = dp[i - 1][j - 1][i - 1];  // First element pick case
                } else {
                    int val = abs(a[i - 1] - a[l - 1]);
                    int res = dp[i - 1][j - 1][l];
                    if (res != INT_MAX) pick = val + res;
                }

                dp[i][j][i] = min(pick, notpick);
            }
        }
    }

    // Finding the minimum cost from the last row
    int ans = INT_MAX;
    for (int l = 1; l <= n; l++) {
        ans = min(ans, dp[n][k][l]);
    }

    return (ans == INT_MAX) ? -1 : ans;  // If no valid partition found, return -1
}

int main() {
    vector<int> a = {96,34,48,8,72,67,90,15,85};
    int k = 5;
    cout << "Minimum cost: " << solve(a.size(), a, k) << endl;
    return 0;
}