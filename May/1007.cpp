#include <iostream>
#include <vector>

using namespace std;

// 1007. Minimum Domino Rotations For Equal Row

class Solution {
    public:
        int check(int x, vector<int>& tops, vector<int>& bottoms) {
            int rotations_top = 0;
            int rotations_bottom = 0;
            int n = tops.size();
    
            for (int i = 0; i < n; ++i) {
                // If x doesn't appear at all on i-th domino, impossible
                if (tops[i] != x && bottoms[i] != x) {
                    return -1;
                } else if (tops[i] != x) {
                    rotations_top++;
                } else if (bottoms[i] != x) {
                    rotations_bottom++;
                }
            }
    
            return min(rotations_top, rotations_bottom);
        }
    
        int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
            int rotations = check(tops[0], tops, bottoms);
            // Try the other candidate only if first one fails or returns -1
            if (rotations != -1) return rotations;
            return check(bottoms[0], tops, bottoms);
        }
    };

int main() {
    Solution solution;

    // Test case 1
    vector<int> tops1 = {2, 1, 2, 4, 2, 2};
    vector<int> bottoms1 = {5, 2, 6, 2, 3, 2};
    cout << "Test 1 Result: " << solution.minDominoRotations(tops1, bottoms1) << endl; // Expected: 2

    // Test case 2
    vector<int> tops2 = {3, 5, 1, 2, 3};
    vector<int> bottoms2 = {3, 6, 3, 3, 4};
    cout << "Test 2 Result: " << solution.minDominoRotations(tops2, bottoms2) << endl; // Expected: -1

    // Additional test case
    vector<int> tops3 = {1, 1, 1, 1};
    vector<int> bottoms3 = {2, 2, 1, 2};
    cout << "Test 3 Result: " << solution.minDominoRotations(tops3, bottoms3) << endl; // Expected: 0

    return 0;
}

