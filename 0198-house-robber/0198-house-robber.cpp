class Solution {
public:
    int robHelper(vector<int>& dp, int n, vector<int>& nums) {
        if (n < 0)
            return 0;
        if (n == 0)
            return nums[0];
        if (dp[n] != -1) {
            return dp[n];
        }
        int lastSecond = nums[n] + robHelper(dp, n - 2, nums);
        int lastOne = 0 + robHelper(dp, n - 1, nums);
        return dp[n] = max(lastSecond, lastOne);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return robHelper(dp, n - 1, nums);
    }
};