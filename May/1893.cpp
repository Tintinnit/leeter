#include <iostream>
#include <vector>

using namespace std;

// 1893. Check if All the Integers in a Range Are Covered

class Solution {
    public:
        bool isCovered(vector<vector<int>>& ranges, int left, int right) {
            int covered = left;

            while (covered <= right) {
                int found = -1;
                for (int i = 0; i < ranges.size(); i++) {
                    if (covered >= ranges[i][0]) {
                        if (ranges[i][1] >= covered) {
                            covered = ranges[i][1] + 1;
                            found = 1;
                        }
                    }
                }

                if (found == -1) {
                    return false;
                }
            }

            return true;
        }
};

