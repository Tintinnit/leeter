#include <iostream>
#include <vector>

using namespace std;

// 1893. Check if All the Integers in a Range Are Covered

class Solution {
    public:
        vector<int> buildArray(vector<int>& nums) {
            vector<int> output;

            for (int i = 0 ; i < nums.size() ; i++) {
                output.emplace_back(nums[nums[i]]);
            }

            return output;
        }
};

int main() {
    Solution solution;

    // Example test case
    vector<int> nums = {0, 2, 1, 5, 3, 4};
    vector<int> result = solution.buildArray(nums);

    // Output the result
    cout << "Result: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
