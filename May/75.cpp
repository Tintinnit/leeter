#include <iostream>
#include <vector>

using namespace std;

// 75. Sort Colors


class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;
        int blue = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                red++;
            } else if (nums[i] == 1) {
                white++;
            } else if (nums[i] == 2) {
                blue++;
            }
        }

        // Loop back through list and place elements
        for (int i = 0; i < nums.size(); i++) {
            if (red > 0) {
                nums[i] = 0;
                red--;
            } else if (white > 0) {
                nums[i] = 1;
                white--;
            } else {
                nums[i] = 2;
            }
        }
    }
};

int main() {
    Solution sol;

    // Example input
    vector<int> nums = {2, 0, 2, 1, 1, 0};

    cout << "Before sorting: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    sol.sortColors(nums);

    cout << "After sorting:  ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
