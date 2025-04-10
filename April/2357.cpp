#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// 2357. Make Array Zero by Subtracting Equal Amounts

class Solution {
    public:
        int minimumOperations(vector<int>& nums) {
            // Note that number of operations needed is equal to number of unique elements in the list
            // Sets can only store unique elements so we go one by one in the array and add them to the set. 
            unordered_set<int> uniqueNonZeros;
            for (int num : nums) {
                if (num != 0) {
                    uniqueNonZeros.insert(num);
                }
            }
            return uniqueNonZeros.size();
        }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 5, 0, 3, 5};
    vector<int> nums2 = {0};
    cout << "Operations for [1,5,0,3,5]: " << solution.minimumOperations(nums1) << endl;
    cout << "Operations for [0]: " << solution.minimumOperations(nums2) << endl;
}