#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// 2094. Finding 3-Digit Even Numbers

class Solution {
    public:
        vector<int> findEvenNumbers(vector<int>& digits) {
            // Map containing frequencies of each digit
            vector<int> mpp(10, 0);
            for (int i = 0; i < digits.size(); i++)
                mpp[digits[i]]++;

            vector<int> result;

            // For first digit, loop from 1 to 9
            for (int i = 1; i <= 9; i++) {
                if (mpp[i] == 0) continue;
                mpp[i]--;
    
                // Middle digit can be any number we want
                for (int j = 0; j <= 9; j++) {
                    if (mpp[j] == 0) continue;
                    mpp[j]--;
                    
                    // For last digit, we only want even numbers, we start at 0, we add 2 until 8
                    for (int k = 0; k <= 8; k += 2) {
                        if (mpp[k] == 0) continue;
                        result.push_back(i*100 + j*10 + k);
                    }
                    mpp[j]++;
    
                }
                mpp[i]++;
            }
            return result;
        }
};

int main() {
    Solution sol;

    vector<int> digits = {2, 1, 3, 0};

    vector<int> output = sol.findEvenNumbers(digits);

    cout << "3-digit even numbers: ";
    for (int num : output) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

