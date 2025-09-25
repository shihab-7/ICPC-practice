#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count_bear_substrings(const string& s) {
    int n = s.size();
    int count = 0;

    // Track the nearest position of "bear" for each starting index
    int next_bear_start = -1;  // Keeps the latest start index of "bear"
    
    for (int i = n - 4; i >= 0; --i) {
        if (s.substr(i, 4) == "bear") {
            next_bear_start = i;
            cout<<next_bear_start<<endl;
        }

        // If there's a valid "bear" starting at or after index i
        if (next_bear_start != -1) {
            // All substrings starting from i up to next_bear_start + 3 (inclusive) are valid
            count += (n - (next_bear_start + 3));
        }
    }

    return count;
}


int main() {
    string s1 ;
    cin >> s1;
    cout << count_bear_substrings(s1) << endl; // Output: 6
    return 0;
}
