class Solution {
public:
    /*
    right now for all number from i to n we are checking number of ones ny
    getting last digit from num & 1 and rightwise shift it by >>1
    */
    vector<int> countBits(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 0; i <= n; i++) {
            dp[i] = dp[i >> 1] + (i & 1);
        }

        return dp;
    }
};