class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int number = 0;
        queue<pair<int, int>> q;
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) {
                q.push({0, j});
                grid[0][j] = 0;
            }
            if (grid[n - 1][j] == 1) {
                q.push({n - 1, j});
                grid[n - 1][j] = 0;
            }
        }

        for (int i = 1; i < n - 1; i++) {
            if (grid[i][0] == 1) {
                q.push({i, 0});
                grid[i][0] = 0;
            }
            if (grid[i][m - 1] == 1) {
                q.push({i, m - 1});
                grid[i][m - 1] = 0;
            }
        }
        while (!q.empty()) {
            auto [u, v] = q.front();
            q.pop();
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, -1, 0, 1};
            for (int i = 0; i < 4; i++) {
                int nrow = u + drow[i];
                int ncol = v + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    grid[nrow][ncol] == 1) {
                    q.push({nrow, ncol});
                    grid[nrow][ncol] = 0;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    number++;
                }
            }
        }
        return number;
    }
};