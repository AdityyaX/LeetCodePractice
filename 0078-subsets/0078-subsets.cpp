class Solution {
public:
    void helper(vector<int>& current, vector<int> nums,
                vector<vector<int>>& result, int i) {
        if (i == nums.size()) {
            result.push_back(current);
            return;
        }
        current.push_back(nums[i]);
        helper(current, nums, result, i + 1);
        current.pop_back();
        helper(current, nums, result, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        int i = 0;
        vector<int> current;
        helper(current, nums, result, i);
        return result;
    }
};