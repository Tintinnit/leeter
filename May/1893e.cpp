#include <iostream>
#include <vector>

using namespace std;

// 1893. Check if All the Integers in a Range Are Covered (More efficient solution) 

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        bool covered[51] = {false};
        
        for (auto& range : ranges) {
            for (int i = range[0]; i <= range[1]; ++i) {
                covered[i] = true;
            }
        }

        for (int i = left; i <= right; ++i) {
            if (!covered[i]) return false;
        }

        return true;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> ranges1 = {{1, 2}, {3, 4}, {5, 6}};
    int left1 = 2, right1 = 5;
    cout << (solution.isCovered(ranges1, left1, right1) ? "true" : "false") << endl;  // Output: true

    vector<vector<int>> ranges2 = {{1, 10}, {10, 20}};
    int left2 = 21, right2 = 21;
    cout << (solution.isCovered(ranges2, left2, right2) ? "true" : "false") << endl;  // Output: false

    vector<vector<int>> ranges3 = {{1, 5}, {6, 10}};
    int left3 = 1, right3 = 10;
    cout << (solution.isCovered(ranges3, left3, right3) ? "true" : "false") << endl;  // Output: true

    return 0;
}
