#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// 2104. Sum of Subarray Ranges
// More efficient

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        return sumOfMax(nums) - sumOfMin(nums);
    }

private:
    long long sumOfMax(const vector<int>& nums) {
        long long res = 0;
        stack<int> s;
        int n = nums.size();

        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && (i == n || nums[s.top()] < nums[i])) {
                int mid = s.top(); s.pop();
                int left = s.empty() ? -1 : s.top();
                int right = i;
                res += (long long)nums[mid] * (mid - left) * (right - mid);
            }
            s.push(i);
        }

        return res;
    }

    long long sumOfMin(const vector<int>& nums) {
        long long res = 0;
        stack<int> s;
        int n = nums.size();

        for (int i = 0; i <= n; ++i) {
            while (!s.empty() && (i == n || nums[s.top()] > nums[i])) {
                int mid = s.top(); s.pop();
                int left = s.empty() ? -1 : s.top();
                int right = i;
                res += (long long)nums[mid] * (mid - left) * (right - mid);
            }
            s.push(i);
        }

        return res;
    }
};

int main() {
    Solution solution;
}
