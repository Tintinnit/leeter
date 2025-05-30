#include <iostream>
#include <vector>

using namespace std;

// 2359. Find Closest Node to Given Two Nodes

class Solution {
public:
    vector<int> getDistances(const vector<int>& edges, int start) {
        int n = edges.size();
        vector<int> dist(n, -1);
        int curr = start, d = 0;

        while (curr != -1 && dist[curr] == -1) {
            dist[curr] = d;
            curr = edges[curr];
            ++d;
        }
        return dist;
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int> dist1 = getDistances(edges, node1);
        vector<int> dist2 = getDistances(edges, node2);
        int n = edges.size();

        int minDist = INT_MAX;
        int result = -1;

        for (int i = 0; i < n; ++i) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    result = i;
                }
            }
        }

        return result;
    }
};

int main() {
    Solution sol;

    // Example 1
    vector<int> edges1 = {2, 2, 3, -1};
    int node1_1 = 0, node2_1 = 1;
    cout << "Test Case 1 Output: " << sol.closestMeetingNode(edges1, node1_1, node2_1) << endl; // Expected: 2

    // Example 2
    vector<int> edges2 = {1, 2, -1};
    int node1_2 = 0, node2_2 = 2;
    cout << "Test Case 2 Output: " << sol.closestMeetingNode(edges2, node1_2, node2_2) << endl; // Expected: 2

    // Custom Example (cycle)
    vector<int> edges3 = {1, 2, 0};
    int node1_3 = 0, node2_3 = 1;
    cout << "Test Case 3 Output: " << sol.closestMeetingNode(edges3, node1_3, node2_3) << endl; // Expected: 1

    return 0;
}
