#include <iostream>
#include <string>

using namespace std;

// 9. Palindrome Number

class Solution {
    public:
        bool isPalindrome(int x) {
            if (x < 0) {
                return false;
            } else {
                string str = to_string(x);
                int len = str.length();
                int half_len = len/2;

                for (int i = 0; i < len/2; i++) {
                    if (str[i] != str[len - i - 1]) {
                        return false;
                    }
                }
            }

            return true;
        }
};
