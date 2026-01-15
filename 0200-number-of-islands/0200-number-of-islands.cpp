class Solution {
public:
    void dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int i,
             int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0' ||
            visited[i][j] == 1) {
            return;
        }
        visited[i][j] = 1;
        dfs(grid, visited, i + 1, j, n, m);
        dfs(grid, visited, i - 1, j, n, m);
        dfs(grid, visited, i, j + 1, n, m);
        dfs(grid, visited, i, j - 1, n, m);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    dfs(grid, visited, i, j, n, m);
                    count++;
                }
            }
        }
        return count;
    }
};