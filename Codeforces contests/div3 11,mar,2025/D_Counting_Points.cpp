#include <iostream>
#include <vector>
#include <unordered_set>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<long long> x(n);
        vector<long long> r(n);
        for (int i = 0; i < n; ++i) {
            cin >> x[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> r[i];
        }

        unordered_set<string> points;
        for (int i = 0; i < n; ++i) {
            long long xi = x[i];
            long long ri = r[i];
            for (long long x_val = xi - ri; x_val <= xi + ri; ++x_val) {
                long long y_max = sqrt(ri * ri - (x_val - xi) * (x_val - xi));
                for (long long y_val = -y_max; y_val <= y_max; ++y_val) {
                    points.insert(to_string(x_val) + "," + to_string(y_val));
                }
            }
        }

        cout << points.size() << '\n';
    }

    return 0;
}