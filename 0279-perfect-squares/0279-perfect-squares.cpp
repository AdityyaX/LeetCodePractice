class Solution {
public:
    int helper(vector<vector<int>>& dp, int n, vector<int>& square, int m) {
        if (n == 0)
            return 0;
        if (m == 0)
            return 1e9;
        if (dp[m][n] != -1)
            return dp[m][n];
        int skip = helper(dp, n, square, m - 1);
        int take = 1e9;
        if (square[m - 1] <= n) {
            take = 1 + helper(dp, n - square[m - 1], square, m);
        }

        return dp[m][n] = min(skip, take);
    }
    int numSquares(int n) {
        vector<int> square;
        for (int i = 1; i * i <= n; i++) {
            square.push_back(i * i);
        }
        int m = square.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return helper(dp, n, square, m);
    }
};