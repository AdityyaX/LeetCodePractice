class Solution {
public:
    int n, m;
    vector<pair<int,int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};

    bool dfs(int i, int j, int idx,
             vector<vector<char>>& board,
             string& word,
             vector<vector<bool>>& visited) {

        if (idx == word.size()) return true;

        if (i < 0 || i >= n || j < 0 || j >= m ||
            visited[i][j] || board[i][j] != word[idx])
            return false;

        visited[i][j] = true;

        for (auto [dr, dc] : directions) {
            if (dfs(i + dr, j + dc, idx + 1, board, word, visited))
                return true;
        }

        visited[i][j] = false;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(i, j, 0, board, word, visited))
                    return true;
            }
        }
        return false;
    }
};
