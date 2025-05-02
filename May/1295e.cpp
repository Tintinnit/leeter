#include <iostream>
#include <vector>

using namespace std;

// 1295. Find Numbers with Even Number of Digits; More efficient solution

class Solution {
    public:
        int findNumbers(vector<int>& nums) {
            int count = 0;
            for (int num : nums) {
                if ((num >= 10 && num <= 99) ||
                    (num >= 1000 && num <= 9999) ||
                    (num == 100000)) {
                    count++;
                }
            }
            return count;
        }
    };


int main() {
    Solution solution;

    vector<int> nums1 = {12, 345, 2, 6, 7896};
    vector<int> nums2 = {555, 901, 482, 1771};
    vector<int> nums3 = {1, 22, 333, 4444, 55555, 100000};

    cout << "Test 1: " << solution.findNumbers(nums1) << endl;
    cout << "Test 2: " << solution.findNumbers(nums2) << endl;
    cout << "Test 3: " << solution.findNumbers(nums3) << endl;

    return 0;
}
