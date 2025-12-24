class Solution {
public:
    int result = 0;
    void helper(vector<int>& nums, int target, int currentValue, int i) {
        if (i == nums.size()) {
            if (currentValue == target) {
                result++;
            }
            return;
        }
        helper(nums, target, currentValue + nums[i], i + 1);
        helper(nums, target, currentValue - nums[i], i + 1);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int currentValue = 0;
        helper(nums, target, currentValue, 0);
        return result;
    }
};