class Solution {
public:
    int solve(vector<int>& nums, vector<int>& dp, int i) {
        if (i == 0) return dp[i] = nums[0];

        if (dp[i] != INT_MIN) return dp[i];
        int extend = nums[i] + solve(nums, dp, i - 1);
        int startNew = nums[i];

        return dp[i] = max(extend, startNew);
    }

    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INT_MIN);
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(nums, dp, i));
        }
        return ans;
    }
};
