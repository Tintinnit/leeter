#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void backtrack(vector<string>& result, string current, int open, int close, int max) {
        // Base case: If the current string has reached the max length
        if (current.length() == max * 2) {
            result.push_back(current);
            return;
        }

        if (open < max) {
            backtrack(result, current + "(", open + 1, close, max);
        }

        if (close < open) {
            backtrack(result, current + ")", open, close + 1, max);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(result, "", 0, 0, n);
        return result;
    }
};

int main() {
    Solution solution;
    int n = 3;
    vector<string> result = solution.generateParenthesis(n);

    for (const string& combination : result) {
        cout << combination << endl;
    }
}