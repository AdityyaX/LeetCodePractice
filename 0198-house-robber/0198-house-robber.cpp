class Solution {
public:
    int helper(vector<int>& dp, vector<int>& nums, int i) {
        if (i < 0)
            return 0;
        if (i == 0)
            return nums[0];

        if (dp[i] != -1)
            return dp[i];

        int included = nums[i] + helper(dp, nums, i - 2);

        int excluded = helper(dp, nums, i - 1);
        dp[i] = max(included, excluded);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return helper(dp, nums, n - 1);
    }
};