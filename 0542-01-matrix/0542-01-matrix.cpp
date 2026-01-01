class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, -1));
        vector<vector<int>> distance(n, vector<int>(m, -1));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    visited[i][j] = 1;
                    distance[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = drow[i] + x;
                int ny = dcol[i] + y;
                if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                    distance[nx][ny] == -1) {
                    distance[nx][ny] = distance[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
        return distance;
    }
};
