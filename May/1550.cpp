#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 1550. Three Consecutive Odds

class Solution {
    public:
        bool threeConsecutiveOdds(vector<int>& arr) {
            int odd_count = 0;
            for (int i = 0; i < arr.size() ; i++) {
                if (arr[i] % 2 == 1) {
                    odd_count++;

                    if (odd_count == 3) {
                        return true;
                    }
                } else {
                    odd_count = 0;
                }
            }

            return false;
        }
};

int main() {
    Solution sol;

    vector<vector<int>> test_cases = {
        {2, 6, 4, 1},            // false
        {1, 2, 34, 3, 4, 5, 7, 23, 12},  // true
        {1, 3, 5},               // true
        {1, 3, 2, 5, 7, 9},      // true
        {2, 4, 6, 8},            // false
        {1, 1, 2, 1, 1, 1}       // true
    };

    for (int i = 0; i < test_cases.size(); ++i) {
        cout << "Test Case " << i + 1 << ": "
             << (sol.threeConsecutiveOdds(test_cases[i]) ? "true" : "false") << endl;
    }

    return 0;
}
