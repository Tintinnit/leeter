#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1710. Maximum Units on a Truck

class Solution {
    public:
        int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
            // Sort by units per box in descending order
            sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b) {
                return a[1] > b[1];
            });

            int totalUnits = 0;

            for (const auto& box : boxTypes) {
                int boxCount = box[0];
                int unitsPerBox = box[1];

                int boxesToTake = min(boxCount, truckSize);
                totalUnits += boxesToTake * unitsPerBox;
                truckSize -= boxesToTake;

                if (truckSize == 0) break;
            }

            return totalUnits;
        }
};

int main() {
    Solution solution;
    vector<vector<int>> boxTypes1 = {{1,3},{2,2},{3,1}};
    vector<vector<int>> boxTypes2 = {{5,10},{2,5},{4,7},{3,9}};
    
    cout << solution.maximumUnits(boxTypes1, 4) << endl;  // Output: 8
    cout << solution.maximumUnits(boxTypes2, 10) << endl; // Output: 91

    return 0;
}