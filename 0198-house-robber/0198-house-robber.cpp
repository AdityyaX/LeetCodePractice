class Solution {
public:
    /*
    what dp[n] represents : max total amount robbed till nth index including it
    transition is max = [i-1],cost[n]+[i-2]
    base case for 0 return 0 index for 1 return max of 0 and 1
    */
    /*
    here got little confused n was passing n instead of n-1 do dry run */
    int robHelper(vector<int>& nums, vector<int>& dp, int i) {
        if (i == 0)
            return nums[0];
        if (i == 1)
            return dp[1] = max(nums[0], nums[1]);

        if (dp[i] != -1) {
            return dp[i];
        }
        int countOne = 0 + robHelper(nums, dp, i - 1);
        int countTwo = nums[i] + robHelper(nums, dp, i - 2);

        return dp[i] = max(countOne, countTwo);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return robHelper(nums, dp, n - 1);
    }
};