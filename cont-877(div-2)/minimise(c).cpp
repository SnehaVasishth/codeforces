#include <bits/stdc++.h>
using namespace std;
#define N 200010

int arr[N];

int main() {

    int t; cin >> t;
    for(int tc = 1; tc <= t; ++tc) {

        int n; cin >> n;

        for(int i = 1; i <= n; ++i) {
            int y; 
            cin >> y;
            arr[y] = i;
        }

        if(arr[n] < min(arr[1], arr[2])) {
            cout << arr[n] << ' ' << min(arr[1], arr[2]) << '\n';
        } else if(arr[n] > max(arr[1], arr[2])) {
            cout << arr[n] << ' ' << max(arr[1], arr[2]) << '\n';
        } else {
            cout << arr[1] << ' ' << arr[2] << '\n';
        }
    }
}