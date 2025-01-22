#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// 4. Median of Two Sorted Arrays

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int x = nums1.size();
        int y = nums2.size();

        int low = 0, high = x;

        while (low <= high) {
            int partitionX = (low + high) / 2;
            int partitionY = (x + y + 1) / 2 - partitionX;

            int maxX = (partitionX == 0) ? numeric_limits<int>::min() : nums1[partitionX - 1];
            int minX = (partitionX == x) ? numeric_limits<int>::max() : nums1[partitionX];

            int maxY = (partitionY == 0) ? numeric_limits<int>::min() : nums2[partitionY - 1];
            int minY = (partitionY == y) ? numeric_limits<int>::max() : nums2[partitionY];

            // Check if we found a correct partition
            if (maxX <= minY && maxY <= minX) {
                // Odd case: We take the max of left partition
                if ((x + y) % 2 == 1) {
                    return max(maxX, maxY);
                }
                // Even case: We take the average of max of left partition and min of right partition
                return (max(maxX, maxY) + min(minX, minY)) / 2.0;
            }
            // Move the binary search window
            else if (maxX > minY) {
                high = partitionX - 1;
            } else {
                low = partitionX + 1;
            }
        }
        throw;
    }
};

int main() {
    Solution solution;
    vector<int> nums1 = {1, 3};
    vector<int> nums2 = {2};
    cout << "Median: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    nums1 = {1, 2};
    nums2 = {3, 4};
    cout << "Median: " << solution.findMedianSortedArrays(nums1, nums2) << endl;

    return 0;
}
