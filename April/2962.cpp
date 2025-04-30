#include <vector>
#include <algorithm>

using namespace std;

// 2962. Count Subarrays Where Max Element Appears at Least K Times

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxVal = *max_element(nums.begin(), nums.end());
        int left = 0, count = 0;
        long long ans = 0;
        int n = nums.size();
        
        for (int right = 0; right < n; ++right) {
            if (nums[right] == maxVal) {
                ++count;
            }
            
            while (count >= k) {
                ans += (n - right);  // all subarrays starting from `left` to end with valid `right`
                if (nums[left] == maxVal) {
                    --count;
                }
                ++left;
            }
        }
        
        return ans;
    }
};

int main() {
    return 0;
}
