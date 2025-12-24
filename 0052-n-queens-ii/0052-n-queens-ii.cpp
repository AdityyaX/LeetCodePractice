// class Solution {
// public:
//     int totalNQueens(int n) {

//     }
// };
class Solution {
    // here intution is we store col diag and diag2 value in thre vectors
    //  we check if left right or col value exist then we continue
    int result;
    vector<bool> col, diag1, diag2;
    int n;

public:
    void backtrack(vector<string>& board, int row) {
        if (row == n) {
            result++;
            return;
        }
        for (int c = 0; c < n; c++) {
            if (col[c] || diag1[row - c + n - 1] || diag2[row + c])
                continue;

            board[row][c] = 'Q';
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = true;
            backtrack(board, row + 1);

            board[row][c] = '.';
            col[c] = diag1[row - c + n - 1] = diag2[row + c] = false;
        }
    }

    int totalNQueens(int N) {
        n = N;
        vector<string> board(n, string(n, '.'));
        col = vector<bool>(n, false);
        diag1 = vector<bool>(2 * n - 1, false);
        diag2 = vector<bool>(2 * n - 1, false);
        backtrack(board, 0);
        return result;
    }
};
