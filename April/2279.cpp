#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// 2279. Maximum Bags With Full Capacity of Rocks

class Solution {
    public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> gaps;

        // Calculate how many rocks each bag still needs
        for (int i = 0; i < capacity.size(); i++) {
            gaps.push_back(capacity[i] - rocks[i]);
        }

        // Sort
        sort(gaps.begin(), gaps.end());

        // Use additionalRocks to fill bags from smallest gap up
        int fullBags = 0;
        for (int gap : gaps) {
            if (gap == 0) {
                fullBags++; // Already full
            } else if (additionalRocks >= gap) {
                additionalRocks -= gap;
                fullBags++;
            } else {
                break;
            }
        }

        return fullBags;
    }
};

int main() {
    Solution solution;
    vector<int> capacity = {2, 3, 4, 5};
    vector<int> rocks = {1, 2, 4, 4};
    int additionalRocks = 2;

    cout << solution.maximumBags(capacity, rocks, additionalRocks) << endl; // Output: 3
}