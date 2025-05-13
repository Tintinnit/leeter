#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


// 17. Letter Combinations of a Phone Number

class Solution {
    public:
        vector<string> letterCombinations(string digits) {
            if (digits.empty()) return {};
    
            unordered_map<char, string> phoneMap = {
                {'2', "abc"}, {'3', "def"},
                {'4', "ghi"}, {'5', "jkl"},
                {'6', "mno"}, {'7', "pqrs"},
                {'8', "tuv"}, {'9', "wxyz"}
            };
    
            vector<string> result;
            string current;
            backtrack(digits, 0, current, result, phoneMap);
            return result;
        }
        void backtrack(const string& digits, int index, string& current, vector<string>& result,
                       unordered_map<char, string>& phoneMap) {
            if (index == digits.size()) {
                result.push_back(current);
                return;
            }
    
            char digit = digits[index];
            for (char letter : phoneMap[digit]) {
                current.push_back(letter);
                backtrack(digits, index + 1, current, result, phoneMap);
                current.pop_back(); // backtrack
            }
        }
};

int main() {
    Solution sol;
    string digits = "23";
    vector<string> combos = sol.letterCombinations(digits);

    cout << "Combinations for \"" << digits << "\":" << endl;
    for (const string& combo : combos) {
        cout << combo << " ";
    }
    cout << endl;

    return 0;
}
