#include <iostream>
#include <string>

using namespace std;

// 9. Palindrome Number, more efficient

class Solution {
    public:
        bool isPalindrome(int x) {
            // Negative numbers and numbers ending in 0 (but not 0 itself) are not palindromes
            if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    
            int reversedHalf = 0;
    
            while (x > reversedHalf) {
                reversedHalf = reversedHalf * 10 + x % 10;
                x /= 10;
            }
    
            // If even number of digits, x == reversedHalf
            // If odd, drop the middle digit: reversedHalf / 10
            return x == reversedHalf || x == reversedHalf / 10;
        }
};
