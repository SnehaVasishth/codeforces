#include <bits/stdc++.h>
using namespace std;

long long solve(int n, vector<int>& a, int k) {
    if (k > n) return -1; // If k > n, no valid subsequence exists

    // Sort the array to minimize absolute differences
    sort(a.begin(), a.end());

    // Use a sliding window to find the minimum sum of absolute differences
    long long result = LLONG_MAX;
    for (int i = 0; i <= n - k; ++i) {
        long long currentSum = 0;
        for (int j = i; j < i + k - 1; ++j) {
            currentSum += abs(a[j + 1] - a[j]);
        }
        result = min(result, currentSum);
    }

    return result == LLONG_MAX ? -1 : result;
}

int main() {
    // Example usage
    vector<int> a = {1,2,3};
    int n = a.size();
    int k = 2;

    long long result = solve(n, a, k);
    cout << "Minimum sum of absolute differences: " << result << endl;

    return 0;
}