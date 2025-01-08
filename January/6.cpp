#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 6. Zigzag Conversion

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s; 
        int len = s.length();
        string result = "";
        for (int i = 0; i < numRows; i++) {
            int current = i;
            result += s[current];
            // Getting index of element in the current row
            int next = current + 1 + (2 * (numRows - 2)) - i;

            while (current < next && next < len) {
                result += s[current];
                current = next;
                next = current + 1 + (2 * (numRows - 2)) - i;
            }
        }
        return result;
    }
};


class Solution2 {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || s.length() <= numRows) {
            return s;
        }

        // Create a vector to store each row
        vector<string> rows(min(numRows, (int)s.length()));
        int curRow = 0;
        bool goingDown = false;

        for (char c : s) {
            rows[curRow] += c; // Add character to the current row
            if (curRow == 0 || curRow == numRows - 1) {
                goingDown = !goingDown; 
            }

            // Moving "cursor" up or down
            curRow += goingDown ? 1 : -1;
        }

        // Combine all rows to form the final string
        string result;
        for (const string& row : rows) {
            result += row;
        }
        return result;
    }
};

int main() {
    Solution2 solution;

    cout << solution.convert("PAYPALISHIRING", 3) << endl;
}

