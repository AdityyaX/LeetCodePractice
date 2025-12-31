class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int time = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                    visited[i][j] = 1;
                } else if (grid[i][j] == 0) {
                    visited[i][j] = 1;
                }
            }
        }
        while (!q.empty()) {
            int size = q.size(); // number of rotten oranges this minute
            bool rotted = false;

            for (int k = 0; k < size; k++) {
                int u = q.front().first;
                int v = q.front().second;
                q.pop();

                int drow[] = {-1, 0, 1, 0};
                int dcol[] = {0, -1, 0, 1};

                for (int i = 0; i < 4; i++) {
                    int nrow = u + drow[i];
                    int ncol = v + dcol[i];

                    if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                        grid[nrow][ncol] == 1) {

                        grid[nrow][ncol] = 2;
                        visited[nrow][ncol] = 1;
                        q.push({nrow, ncol});
                        rotted = true;
                    }
                }
            }

            if (rotted)
                time++;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        return time;
    }
};