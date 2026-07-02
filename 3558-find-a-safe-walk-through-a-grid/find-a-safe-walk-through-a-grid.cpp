class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size(), n = grid[0].size();

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        deque<pair<int,int>> dq;

        dist[0][0] = grid[0][0];
        dq.push_front({0, 0});

        int dirs[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();

            for (auto &d : dirs) {
                int nx = x + d[0];
                int ny = y + d[1];

                if (nx < 0 || nx >= m || ny < 0 || ny >= n) continue;

                int newCost = dist[x][y] + grid[nx][ny];

                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;

                    if (grid[nx][ny] == 1)
                        dq.push_back({nx, ny});
                    else
                        dq.push_front({nx, ny});
                }
            }
        }

        return dist[m - 1][n - 1] < health;
    }
};