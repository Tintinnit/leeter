#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

// 3342. Find Minimum Time to Reach Last Room II

class State {
    public:
        int x, y, dis, parity;
        State(int x, int y, int dis, int parity) : x(x), y(y), dis(dis), parity(parity) {}
    };

class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int inf = 0x3f3f3f3f;
        int n = moveTime.size(), m = moveTime[0].size();
        
        vector<vector<vector<int>>> d(n, vector<vector<int>>(m, vector<int>(2, inf)));
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(2, false)));

        int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        d[0][0][0] = 0;

        auto cmp = [](const State& a, const State& b) {
            return a.dis > b.dis;
        };

        priority_queue<State, vector<State>, decltype(cmp)> pq(cmp);
        pq.emplace(0, 0, 0, 0);

        while (!pq.empty()) {
            State s = pq.top(); pq.pop();

            if (visited[s.x][s.y][s.parity]) continue;
            visited[s.x][s.y][s.parity] = true;

            for (int i = 0; i < 4; ++i) {
                int nx = s.x + dirs[i][0];
                int ny = s.y + dirs[i][1];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

                int moveDuration = (s.parity == 0) ? 1 : 2;
                int arrivalTime = s.dis + moveDuration;

                // Wait *after* moving if we arrive too early
                if (arrivalTime < moveTime[nx][ny]) {
                    arrivalTime = moveTime[nx][ny];
                }

                int newParity = 1 - s.parity;

                if (arrivalTime < d[nx][ny][newParity]) {
                    d[nx][ny][newParity] = arrivalTime;
                    pq.emplace(nx, ny, arrivalTime, newParity);
                }
            }
        }

        return min(d[n-1][m-1][0], d[n-1][m-1][1]);
    }
};
    

int main() {
    Solution sol;

    vector<vector<int>> input1 = {{0, 4}, {4, 4}};
    cout << "Expected: 7, Got: " << sol.minTimeToReach(input1) << endl;

    vector<vector<int>> input2 = {{0, 0, 0, 0}, {0, 0, 0, 0}};
    cout << "Expected: 6, Got: " << sol.minTimeToReach(input2) << endl;

    vector<vector<int>> input3 = {{0, 1}, {1, 2}};
    cout << "Expected: 4, Got: " << sol.minTimeToReach(input3) << endl;
}

