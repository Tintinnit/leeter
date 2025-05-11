#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 2918. Minimum Equal Sum of Two Arrays After Replacing Zeros

class Solution {
    public:
        long long minSum(vector<int>& nums1, vector<int>& nums2) {
            long long num1_total = 0;
            int num1_zeroes = 0;
            long long num2_total = 0;
            int num2_zeroes = 0;

            for (int i = 0 ; i < nums1.size() ; i++) {
                if (nums1[i] == 0 ) {
                    num1_zeroes++;
                }

                num1_total += nums1[i];
            }

            for (int i = 0 ; i < nums2.size() ; i++) {
                if (nums2[i] == 0 ) {
                    num2_zeroes++;
                }

                num2_total += nums2[i];
            }

            if (num1_zeroes != 0 && num2_zeroes != 0) {
                return max(num1_total + num1_zeroes, num2_total + num2_zeroes);
            }

            if (num1_total > num2_total) {
                if ((num1_total - num2_total) >= num2_zeroes && num2_zeroes != 0) {
                    return num1_total;
                }
            }

            if (num2_total > num1_total) {
                if ((num2_total - num1_total) >= num1_zeroes && num1_zeroes != 0) {
                    return num2_total;
                }
            }

            if (num1_zeroes == 0 && num2_zeroes == 0) {
                if (num1_total == num2_total) {
                    return num1_total;
                }
            } 

            return -1;
        }
};

int main() {
    Solution sol;

    vector<int> nums1_1 = {3, 2, 0, 1, 0};
    vector<int> nums2_1 = {6, 5, 0};
    cout << "Test Case 1: " << sol.minSum(nums1_1, nums2_1) << endl;  // Output: 12

    vector<int> nums1_2 = {2, 0, 2, 0};
    vector<int> nums2_2 = {1, 4};
    cout << "Test Case 2: " << sol.minSum(nums1_2, nums2_2) << endl;  // Output: -1

    vector<int> nums1_3 = {1, 2, 3};
    vector<int> nums2_3 = {2, 2, 2};
    cout << "Test Case 3: " << sol.minSum(nums1_3, nums2_3) << endl;  // Output: 6

    vector<int> nums1_4 = {0, 0};
    vector<int> nums2_4 = {1, 1};
    cout << "Test Case 4: " << sol.minSum(nums1_4, nums2_4) << endl;  // Output: 2

    return 0;
}
