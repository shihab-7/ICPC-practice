
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Sort the list to work with consecutive gaps
        sort(a.begin(), a.end());

        // Calculate the minimum required k based on the largest gap
        long long max_half_gap = 0;
        for (int i = 1; i < n; i++) {
            long long gap = a[i] - a[i - 1];
            max_half_gap = max(max_half_gap, (gap + 1) / 2);
        }

        // Output the required k for this test case
        cout << max_half_gap << endl;
    }

    return 0;
}
