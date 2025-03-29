#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minSeconds(vector<int>& amount) {
    // Sort the array to make processing easier
    sort(amount.begin(), amount.end(), greater<int>());

    int maxSnacks = amount[0];  // Maximum number of a single snack needed
    int sumSnacks = amount[0] + amount[1] + amount[2];  // Total number of snacks

    // The minimum time required is the maximum of either:
    // 1. The highest single type of snack count (since we can at most take 2 at a time)
    // 2. The total number of snacks divided by 2 (ceiling value)
    return max(maxSnacks, (sumSnacks + 1) / 2);
}

int main() {
    vector<int> amount = {7,2,3}; // Example input
    cout << "Minimum seconds needed: " << minSeconds(amount) << endl;
    return 0;
}
