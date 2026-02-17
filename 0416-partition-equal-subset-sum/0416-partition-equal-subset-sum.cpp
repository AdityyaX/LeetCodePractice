class Solution {
public:
    bool helper(vector<int>& nums, vector<vector<int>>& dp, int n, int target) {
        if (target == 0)
            return true;
        if (n == 0)
            return nums[0] == target;
        if (dp[n][target] != -1)
            return dp[n][target];

        bool notTaken = helper(nums, dp, n - 1, target);
        bool taken = false;
        if (nums[n] <= target) {
            taken = helper(nums, dp, n - 1, target - nums[n]);
        }
        return dp[n][target] = notTaken || taken;
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (auto it : nums) {
            sum += it;
        }
        if (sum % 2 == 1) {
            return false;
        } else {
            int k = sum / 2;
            vector<vector<int>> dp(n, vector<int>(k + 1, -1));
            return helper(nums, dp, n - 1, k);
        }
    }
};