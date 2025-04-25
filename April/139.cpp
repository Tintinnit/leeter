#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

// 139. Word Break

class Solution {
    public:
        bool wordBreak(string s, vector<string>& wordDict) {
            unordered_set<string> dict(wordDict.begin(), wordDict.end());
            int n = s.length();
            vector<bool> dp(n + 1, false);
            dp[0] = true; // empty string
    
            for (int i = 1; i <= n; ++i) {
                for (int j = 0; j < i; ++j) {
                    string word = s.substr(j, i - j);
                    if (dp[j] && dict.count(word)) {
                        dp[i] = true;
                        break; // no need to check further j's
                    }
                }
            }
    
            return dp[n];
        }
};

int main() {
    Solution solution;

    // Test Case 1
    string s1 = "leetcode";
    vector<string> dict1 = {"leet", "code"};
    cout << "Test Case 1: " << (solution.wordBreak(s1, dict1) ? "true" : "false") << endl;

    // Test Case 2
    string s2 = "applepenapple";
    vector<string> dict2 = {"apple", "pen"};
    cout << "Test Case 2: " << (solution.wordBreak(s2, dict2) ? "true" : "false") << endl;

    // Test Case 3
    string s3 = "catsandog";
    vector<string> dict3 = {"cats", "dog", "sand", "and", "cat"};
    cout << "Test Case 3: " << (solution.wordBreak(s3, dict3) ? "true" : "false") << endl;

    // Test Case 4 - edge case: empty string
    string s4 = "";
    vector<string> dict4 = {"a"};
    cout << "Test Case 4 (empty string): " << (solution.wordBreak(s4, dict4) ? "true" : "false") << endl;

    // Test Case 5 - reuse word multiple times
    string s5 = "aaaaaaa";
    vector<string> dict5 = {"a", "aa", "aaa"};
    cout << "Test Case 5 (repeating words): " << (solution.wordBreak(s5, dict5) ? "true" : "false") << endl;

    return 0;
}
