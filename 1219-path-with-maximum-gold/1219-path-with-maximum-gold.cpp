class Solution {
public:
    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int helper(int i, int j, int m, int n, vector<vector<int>>& grid,
               vector<vector<bool>>& visited) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0 ||
            visited[i][j]) {
            return 0;
        }
        int gold = grid[i][j];
        visited[i][j] = true;
        int best = 0;

        for (auto [dx, dy] : directions) {
            best = max(best, helper(i + dx, j + dy, m, n, grid, visited));
        }
        visited[i][j] = false;
        return gold + best;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid[0].size();
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    int result = helper(i, j, m, n, grid, visited);
                    ans = max(ans, result);
                }
            }
        }
        return ans;
    }
};