#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, a, b, k;
    cin >> n >> a >> b >> k;

    string shots;
    cin >> shots;

    vector<int> targetCells;
    int count = 0;

    for (int i = 0; i < n; ++i) {
        if (shots[i] == '0') {
            count++;
            if (count == b) {
                // We have a segment of 'b' consecutive '0's, so we take a shot
                targetCells.push_back(i + 1);  // Record 1-based position
                count = 0;  // Reset count after taking a shot
            }
        } else {
            count = 0;  // Reset count if there is a '1' (missed shot position)
        }
    }

    // Output the results
    cout << targetCells.size() << endl;
    for (int cell : targetCells) {
        cout << cell << " ";
    }
    cout << endl;

    return 0;
}
