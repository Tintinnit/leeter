#include <iostream>
#include <vector>

using namespace std;

// 3355. Zero Array Transformation I

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> delta(n + 1, 0);

        for (auto& q : queries) {
            int l = q[0], r = q[1];
            delta[l] += 1;
            if (r + 1 < n) delta[r + 1] -= 1;
        }

        // Apply prefix sum to compute total decrements at each index
        int running = 0;
        for (int i = 0; i < n; ++i) {
            running += delta[i];
            if (running < nums[i]) return false;
        }

        return true;
    }
};

int main() {
    Solution sol;

    // Test Case 1
    vector<int> nums1 = {1, 0, 1};
    vector<vector<int>> queries1 = {{0, 2}};
    cout << "Test Case 1: " << (sol.isZeroArray(nums1, queries1) ? "true" : "false") << endl;

    // Test Case 2
    vector<int> nums2 = {4, 3, 2, 1};
    vector<vector<int>> queries2 = {{1, 3}, {0, 2}};
    cout << "Test Case 2: " << (sol.isZeroArray(nums2, queries2) ? "true" : "false") << endl;

    // Test Case 3 - Edge Case
    vector<int> nums3 = {0, 0, 0};
    vector<vector<int>> queries3 = {};
    cout << "Test Case 3: " << (sol.isZeroArray(nums3, queries3) ? "true" : "false") << endl;

    return 0;
}
