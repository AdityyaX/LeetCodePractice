class Solution {
public:
    int climbStairsHelper(vector<int>& dp, int n) {
        if (n <= 1)
            return 1;
        if (dp[n] != -1)
            return dp[n];
        dp[n] = climbStairsHelper(dp, n - 1) + climbStairsHelper(dp, n - 2);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return climbStairsHelper(dp, n);
    }
};