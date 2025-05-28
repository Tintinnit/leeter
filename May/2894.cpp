#include <iostream>
#include <vector>

using namespace std;

// 2894. Divisible and Non-divisible Sums Difference

class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1 = 0 ;
        int num2 = 0 ;

        for (int i = 1 ; i <= n ; i++) {
            if (i % m == 0) {
                num2 += i;
            } else {
                num1 += i;
            }
        }

        return num1 - num2;
    }
};

int main() {
    Solution sol;

    cout << sol.differenceOfSums(10, 3) << endl; // 19
    cout << sol.differenceOfSums(5, 6) << endl; // 15
    cout << sol.differenceOfSums(5, 1) << endl; // -15
}

