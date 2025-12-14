class Solution {
public:
    /*
    here my approach should be go to every index and check if it is 1 and
    increase number of osland traverse then then do for all indexes where i j
    =1*/
    void dfs(int i, int j, vector<vector<char>>& grid) {
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() ||
            grid[i][j] == '0')
            return;
        grid[i][j] = '0';
        dfs(i + 1, j, grid);
        dfs(i - 1, j, grid);
        dfs(i, j + 1, grid);
        dfs(i, j - 1, grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int numberOfIslands = 0;
        int n = grid.size();
        int m = grid[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    numberOfIslands++;
                    dfs(i, j, grid);
                }
            }
        }
        return numberOfIslands;
    }
};