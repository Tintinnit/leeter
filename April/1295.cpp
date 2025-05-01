#include <iostream>
#include <vector>

using namespace std;

// 1295. Find Numbers with Even Number of Digits

class Solution {
    public:
        bool digits(int num) {
            int count = 0; 
            while (num != 0) {
                num /= 10;
                count++;
            }

            return count %2 == 0;
        }

        int findNumbers(vector<int>& nums) {
            int size = nums.size();
            int count = 0;

            for (int i = 0; i < size; i++) {
                if (digits(nums[i]) == 1) {
                    count++;
                }
            }

            return count;
        }
    };


int main() {
    Solution solution;

    return 0;
}