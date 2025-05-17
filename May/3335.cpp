#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// 3335. Total Characters in String After Transformations I

class Solution {
    public:
        const int MOD = 1e9 + 7;
    
        int lengthAfterTransformations(string s, int t) {
        unordered_map<char, long long> count;
        for (char c : s) {
            count[c]++;
        }
    
        for (int i = 0; i < t; ++i) {
            unordered_map<char, long long> new_count;
            for (auto& pair : count) {
                char c = pair.first;
                long long cnt = pair.second;
                if (c == 'z') {
                    new_count['a'] += cnt;
                    new_count['b'] += cnt;
                } else {
                    char next_char = c + 1;
                    new_count[next_char] += cnt;
                }
            }
            count = new_count;
        }
    
        long long total = 0;
        for (auto& pair : count) {
            total += pair.second;
        }
        return total % MOD;
        }
};
