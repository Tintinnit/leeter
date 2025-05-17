#include <vector>
#include <string>
#include <unordered_map>
#include <iostream>

using namespace std;

// 3335. Total Characters in String After Transformations I

class Solution {
    public:
        const int MOD = 1e9 + 7;
        int mod_add(int a, int b) {a = a % MOD; b = b % MOD; return (((a + b) % MOD) + MOD) % MOD;}
        
        int lengthAfterTransformations(string s, int t) {
            int nums[26] = {0};
            for (char ch : s) nums[ch - 'a']++;
            while (t--) {
                int cur[26] = {0};
                for (int j = 0; j < 26; j++) {
                    if (j == 25 && nums[j] > 0) {
                        cur[0] = mod_add(cur[0], nums[j]);
                        cur[1] = mod_add(cur[1], nums[j]);
                    } else {
                        if (j < 25) cur[j + 1] = mod_add(cur[j + 1], nums[j]);
                    }
                }
                for (int j = 0; j < 26; j++) nums[j] = cur[j];
            }
            int ans = 0;
            for (int i : nums) ans = mod_add(ans, i);
            return (int)ans;
        }
};

int main() {
    Solution sol;

    // Test Case 1
    string s1 = "abc";
    int t1 = 1;
    cout << "Test Case 1: " << sol.lengthAfterTransformations(s1, t1) << endl;

    // Test Case 2
    string s2 = "z";
    int t2 = 2;
    cout << "Test Case 2: " << sol.lengthAfterTransformations(s2, t2) << endl;

    // Test Case 3
    string s3 = "az";
    int t3 = 3;
    cout << "Test Case 3: " << sol.lengthAfterTransformations(s3, t3) << endl;

    // Test Case 4 - edge case with t = 0
    string s4 = "abc";
    int t4 = 0;
    cout << "Test Case 4: " << sol.lengthAfterTransformations(s4, t4) << endl;

    return 0;
}
