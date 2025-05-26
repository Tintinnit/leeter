#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 2131. Longest Palindrome by Concatenating Two Letter Words

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count[26][26] = {};
        int length = 0;

        for (string& word : words) {
            int a = word[0] - 'a';
            int b = word[1] - 'a';

            // If a reverse pair exists, match it
            if (count[b][a] > 0) {
                count[b][a]--;
                length += 4;
            } else {
                count[a][b]++;
            }
        }

        // Now check for any remaining same-letter pair like "gg"
        for (int i = 0; i < 26; i++) {
            if (count[i][i] > 0) {
                length += 2; // We can place one in the center
                break;
            }
        }

        return length;
    }
};

int main() {
    Solution sol;
    
    vector<string> words1 = {"lc", "cl", "gg"};
    cout << "Output: " << sol.longestPalindrome(words1) << endl; // 6

    vector<string> words2 = {"ab", "ty", "yt", "lc", "cl", "ab"};
    cout << "Output: " << sol.longestPalindrome(words2) << endl; // 8

    vector<string> words3 = {"cc", "ll", "xx"};
    cout << "Output: " << sol.longestPalindrome(words3) << endl; // 2

    return 0;
}
