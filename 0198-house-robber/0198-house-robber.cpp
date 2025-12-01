class Solution {
public:
    int robHelper(vector<int>& dp, vector<int>& nums, int i) {
        if (i >= nums.size())
            return 0;

        if (dp[i] != -1) {
            return dp[i];
        }
        int left = 0 + robHelper(dp, nums, i + 1);
        int right = nums[i] + robHelper(dp, nums, i + 2);
        dp[i] = max(left, right);
        return dp[i];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n + 1, -1);
        return robHelper(dp, nums, 0);
    }
};