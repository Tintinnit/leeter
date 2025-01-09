#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        string result(s.length(), ' ');
        int step = 2 * (numRows - 1);
        int pos = 0;

        // Iterate over each row
        for (int row = 0; row < numRows; row++) {
            for (int i = row; i < s.length(); i += step) {
                result[pos++] = s[i];
                
                if (row > 0 && row < numRows - 1) {
                    int diag = i + step - 2 * row;
                    if (diag < s.length()) {
                        result[pos++] = s[diag];
                    }
                }
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    cout << solution.convert("PAYPALISHIRING", 3) << endl;
}
