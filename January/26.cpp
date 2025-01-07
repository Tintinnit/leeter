#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 26. Remove Duplicates from Sorted Array

class Solution {
    public:
        int removeDuplicates(vector<int>& nums) {
            int index = 1;
            int current = nums[0];
            int output = 1;

            for (auto &i : nums) {
                if (i != current) {
                    current = i;
                    nums[index] = i;
                    index++;
                    output++;
                }
            }

            return output;
        }
};

int main() {

}