#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 3392. Count Subarrays of Length Three With a Condition

class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int count = 0;

        for (int i = 0; i < nums.size() - 2; i++) {
            if ((nums[i] + nums[i + 2]) * 2 == nums[i + 1]) {
                count++;
            }
        }

        return count;
        
    }
};

int main() {
    return 0;
}
