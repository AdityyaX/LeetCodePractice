class Solution {
public:
    bool canJumpHelper(vector<int>& nums, vector<int>& dp, int n) {
        int size = nums.size();
        if (n >= size - 1)
            return true;
        if (dp[n] != -1)
            return dp[n] == 1;

        int maxJump = nums[n];

        for (int step = 1; step <= maxJump; step++) {
            int next = n + step;
            if (next < size && canJumpHelper(nums, dp, next)) {
                dp[n] = 1;
                return true;
            }
        }

        dp[n] = 0;
        return false;
    }

    bool canJump(vector<int>& nums) {
        // what dp[i] represent in this case
        // here dp[i]represent true or false which is it is reachable of not
        // from 1 or not
        // what are the choice i should take at each position
        // which step i should take out of i to i+nums[i] position
        // what is the reccurence here
        // for any dp[j] upto n-1 if j+dp[j]>=i position then dp[i]=true
        // base dp[0] = true
        int n = nums.size();
        vector<int> dp(n, -1);
        return canJumpHelper(nums, dp, 0);
    }
};