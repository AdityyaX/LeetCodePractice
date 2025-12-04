/*
here dp[n] represent maximum amount only but here base condition also includ
dp[n]==1 transition is also same base condition here can be implement simple
hoise rebber for 0 to n-2 and 1 to n-1 return max becuase ?*/
class Solution {
public:
    int robLinear(vector<int>& nums, int start, int end, vector<int>& dp) {
        if (start == end)
            return nums[start];

        if (end - start == 1)
            return max(nums[start], nums[end]);

        if (dp[end] != -1)
            return dp[end];

        int skip = robLinear(nums, start, end - 1, dp);
        int take = nums[end] + robLinear(nums, start, end - 2, dp);

        return dp[end] = max(skip, take);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];

        vector<int> dp1(n, -1);
        vector<int> dp2(n, -1);

        int case1 = robLinear(nums, 0, n - 2, dp1);
        int case2 = robLinear(nums, 1, n - 1, dp2);

        return max(case1, case2);
    }
};