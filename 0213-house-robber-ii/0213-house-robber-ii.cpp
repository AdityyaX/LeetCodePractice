class Solution {
public:
    int helper(vector<int>& nums, vector<int>& dp, int start, int end) {
        if (end < start)
            return 0;

        if (start == end)
            return nums[start];
        if (end - start == 1)
            return max(nums[start], nums[end]);
        if (dp[end] != -1)
            return dp[end];
        int take = nums[end] + helper(nums, dp, start, end - 2);
        int skip = helper(nums, dp, start, end - 1);
        return dp[end] = max(skip, take);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);
        int leftCase = helper(nums, dp1, 0, n - 2);
        int rightCase = helper(nums, dp2, 1, n - 1);
        return max(leftCase, rightCase);
    }
};