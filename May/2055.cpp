#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 2055. Plates Between Candles

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<int> prefixPlates(n, 0);
        vector<int> leftCandle(n, -1);
        vector<int> rightCandle(n, -1);

        prefixPlates[0] = s[0] == '*' ? 1 : 0;
        for (int i = 1; i < n; ++i) {
            prefixPlates[i] = prefixPlates[i - 1] + (s[i] == '*' ? 1 : 0);
        }

        // Nearest candle to the left of i
        int last = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '|') last = i;
            leftCandle[i] = last;
        }

        // Nearest candle to the right of i
        last = -1;
        for (int i = n - 1; i >= 0; --i) {
            if (s[i] == '|') last = i;
            rightCandle[i] = last;
        }

        // Processing each query
        vector<int> result;
        for (const auto& q : queries) {
            int left = rightCandle[q[0]];
            int right = leftCandle[q[1]];
            if (left != -1 && right != -1 && left < right) {
                result.push_back(prefixPlates[right] - prefixPlates[left]);
            } else {
                result.push_back(0);
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    string s = "***|**|*****|**||**|*";
    vector<vector<int>> queries = {
        {1, 17}, {4, 5}, {14, 17}, {5, 11}, {15, 16}
    };

    vector<int> result = sol.platesBetweenCandles(s, queries);

    cout << "Results: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

