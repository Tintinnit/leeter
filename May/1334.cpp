#include <vector>
#include <unordered_map>
#include <queue>
#include <utility>
#include <functional>
#include <climits>
#include <iostream>

using namespace std;

// 1334. Find the City With the Smallest Number of Neighbors at a Threshold Distance

class Solution {
public:
    #define P pair<int, int>

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        unordered_map<int, vector<P>> adj;

        // Build adjacency list
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        auto dijkstra = [&](int src) -> int {
            vector<int> dist(n, INT_MAX);
            dist[src] = 0;

            priority_queue<P, vector<P>, greater<>> heap;
            heap.push({0, src});

            while (!heap.empty()) {
                auto [cur_dist, u] = heap.top();
                heap.pop();

                for (auto [v, weight] : adj[u]) {
                    int new_dist = cur_dist + weight;
                    if (new_dist < dist[v]) {
                        dist[v] = new_dist;
                        heap.push({new_dist, v});
                    }
                }
            }

            // Count reachable cities within threshold (excluding src)
            int count = 0;
            for (int i = 0; i < n; ++i) {
                if (i != src && dist[i] <= distanceThreshold) {
                    count++;
                }
            }
            return count;
        };

        int result = -1;
        int min_count = n;

        for (int city = 0; city < n; ++city) {
            int reachable = dijkstra(city);
            if (reachable <= min_count) {
                min_count = reachable;
                result = city;
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Example 1
    int n1 = 4;
    vector<vector<int>> edges1 = {{0, 1, 3}, {1, 2, 1}, {1, 3, 4}, {2, 3, 1}};
    int threshold1 = 4;
    int result1 = solution.findTheCity(n1, edges1, threshold1);
    cout << "Output for Example 1: " << result1 << " (Expected: 3)" << endl;

    // Example 2
    int n2 = 5;
    vector<vector<int>> edges2 = {{0, 1, 2}, {0, 4, 8}, {1, 2, 3}, {1, 4, 2}, {2, 3, 1}, {3, 4, 1}};
    int threshold2 = 2;
    int result2 = solution.findTheCity(n2, edges2, threshold2);
    cout << "Output for Example 2: " << result2 << " (Expected: 0)" << endl;

    return 0;
}
