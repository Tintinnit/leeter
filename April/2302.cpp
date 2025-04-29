#include <vector>

using namespace std;

// 2302. Count Subarrays With Score Less Than K

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long sum = 0;
        int left = 0;
        long long ans = 0;
        
        for (int right = 0; right < nums.size(); ++right) {
            sum += nums[right];
            
            while (sum * (right - left + 1) >= k) {
                sum -= nums[left];
                ++left;
            }
            
            ans += (right - left + 1);
        }
        
        return ans;
    }
};

int main() {
    return 0;
}
