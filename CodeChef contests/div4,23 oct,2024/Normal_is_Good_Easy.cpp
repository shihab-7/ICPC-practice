#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T; // Number of test cases
    while (T--) {
        int N;
        cin >> N; // Length of the array
        vector<int> A(N);
        
        for (int i = 0; i < N; i++) {
            cin >> A[i]; // Read the elements of the array
        }
        
        unordered_map<int, int> balance_count; // Map to count balances
        balance_count[0] = 1; // Initial balance
        
        int count_1 = 0, count_2 = 0;
        long long normal_subarrays = 0;
        
        for (int i = 0; i < N; i++) {
            // Count the number of 1s and 2s
            if (A[i] == 1) count_1++;
            else count_2++;
            
            // Calculate the balance
            int balance = count_1 - count_2;

            // Add to the normal subarrays count based on how many times we've seen this balance
            normal_subarrays += balance_count[balance];

            // Increment the count for this balance
            balance_count[balance]++;
        }
        
        // Output the result for the current test case
        cout << normal_subarrays << endl;
    }

    return 0;
}
