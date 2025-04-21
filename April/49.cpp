#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 49. Group Anagrams

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramGroups;

        for (const string& word : strs) {
            string sortedWord = word;
            sort(sortedWord.begin(), sortedWord.end());

            anagramGroups[sortedWord].push_back(word);
        }

        vector<vector<string>> result;
        for (auto& entry : anagramGroups) {
            result.push_back(entry.second);
        }

        return result;
    }
};

int main() {
    Solution solution;
    vector<string> input = {"eat","tea","tan","ate","nat","bat"};
    vector<vector<string>> result = solution.groupAnagrams(input);

    for (const auto& group : result) {
        cout << "[ ";
        for (const string& word : group) {
            cout << word << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
