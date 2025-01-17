#include <iostream>

using namespace std;

// 191. Number of 1 Bits

class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while (n != 0) {
            count += n & 1;
            n >>= 1;       
        }
        return count;
    }
};

int main() {
    Solution solution;
    cout << solution.hammingWeight(11) << endl;
    cout << solution.hammingWeight(128) << endl;
    cout << solution.hammingWeight(2147483645) << endl;
}
