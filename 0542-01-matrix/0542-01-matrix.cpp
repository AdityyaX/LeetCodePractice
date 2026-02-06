class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> distance(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    distance[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            int drow[] = {-1, 0, 1, 0};
            int dcol[] = {0, -1, 0, 1};
            for (int i = 0; i < 4; i++) {
                int nrow = x + drow[i];
                int ncol = y + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    distance[nrow][ncol] == -1) {
                    distance[nrow][ncol] = distance[x][y] + 1;
                    q.push({nrow, ncol});
                }
            }
        }

        return distance;
    }
};