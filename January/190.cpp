#include <iostream>

using namespace std;

// 190. Reverse Bits


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            int bit = n & 1;

            // Shift the bit to its reversed position and add to result
            result = (result << 1) | bit;

            n >>= 1;
        }
        return result;
    }
};

int main() {
    Solution solution;
    uint32_t n1 = 0b00000010100101000001111010011100;
    uint32_t n2 = 0b11111111111111111111111111111101;

    cout << solution.reverseBits(n1) << endl;
    cout << solution.reverseBits(n2) << endl;

    return 0;
}
