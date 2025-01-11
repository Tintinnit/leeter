#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 1. Two Sum 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numMap;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            // Check if the complement is already in the map
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }

            numMap[nums[i]] = i;
        }

        return {};
    }
};

int main () {

}