#include <iostream>
#include <vector>

using namespace std;

// 2104. Sum of Subarray Ranges
// Brute force solution

class Solution {
    public:
        long long subArrayRanges(vector<int>& nums) {
            long long total = 0;
            for (int i = 0; i < nums.size(); ++i) {
                int minVal = nums[i];
                int maxVal = nums[i];
                for (int j = i; j < nums.size(); ++j) {
                    minVal = min(minVal, nums[j]);
                    maxVal = max(maxVal, nums[j]);
                    total += (maxVal - minVal);
                }
            }
            return total;
        }
};

int main() {
    Solution solution;
}
