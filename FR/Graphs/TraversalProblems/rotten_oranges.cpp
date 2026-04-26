class Solution {
   public:
    int orangesRotting(vector<vector<int>> &grid) {
        // push all 2's to queue for bfs traversal
        // each time we take out all values in Q and find neg 1 and mark it 2
        // time++

        vector<pair<int, int>> dir = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

        queue<pair<int, int>> q;
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) q.push({i, j});
            }
        }

        int time = -1;

        while (!q.empty()) {
            int qSize = q.size();

            for (int t = 0; t < qSize; t++) {
                auto [ci, cj] = q.front();
                q.pop();

                for (auto d : dir) {
                    int n_i = ci + d.first, n_j = cj + d.second;

                    if (n_i >= 0 && n_j >= 0 && n_i < n && n_j < m &&
                        grid[n_i][n_j] == 1) {
                        grid[n_i][n_j] = 2;
                        q.push({n_i, n_j});
                    }
                }
            }
            time++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) return -1;
            }
        }

        return time==-1 ? 0 : time;
    }
};