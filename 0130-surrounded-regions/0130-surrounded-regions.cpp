class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0)
            return;
        int m = board[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O')
                q.push({i, 0});
            if (board[i][m - 1] == 'O')
                q.push({i, m - 1});
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O')
                q.push({0, j});
            if (board[n - 1][j] == 'O')
                q.push({n - 1, j});
        }

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            if (board[x][y] != 'O')
                continue;
            board[x][y] = '#';
            for (int i = 0; i < 4; i++) {
                int nrow = x + drow[i];
                int ncol = y + dcol[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                    board[nrow][ncol] == 'O') {
                    q.push({nrow, ncol});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
    }
};