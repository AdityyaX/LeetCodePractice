class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& result,
                vector<int>& current, int i) {
        if (i == nums.size()) {
            result.push_back(current);
            return;
        }
        current.push_back(nums[i]);
        helper(nums, result, current, i + 1);
        current.pop_back();
        helper(nums, result, current, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        int i = 0;
        helper(nums, result, current, i);
        return result;
    }
};