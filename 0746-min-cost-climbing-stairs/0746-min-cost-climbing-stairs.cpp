class Solution {
public:
/* here intution for this is 
first question asked what dp[n]represent here it show min cost to reach that step
the transition function is clear here  dp[n] depends on min of n-1 and n-2
base case here is if i have 1 number the return that if 2 then return. second as we will calculating min of both
*/
    int minCostClimbingStairsHelper(vector<int>& cost, vector<int>& dp, int n) {
        if (n == 0) {
            return cost[0];
        }
        if (n == 1) {
            return cost[1];
        }
        if (dp[n] != -1)
            return dp[n];
        int last = cost[n] + minCostClimbingStairsHelper(cost, dp, n - 1);
        int secondLast = cost[n] + minCostClimbingStairsHelper(cost, dp, n - 2);
        dp[n] = min(last, secondLast);
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        int last = minCostClimbingStairsHelper(cost, dp, n - 1);
        int secondLast = minCostClimbingStairsHelper(cost, dp, n - 2);
        return min(last, secondLast);
    }
};