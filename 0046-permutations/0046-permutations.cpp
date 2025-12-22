class Solution {
    // in this we keep a vector of unused vector for computation
private:
    vector<vector<int>> result;
    vector<int> used;
    void helper(vector<int> current, vector<int> nums, int i) {
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            used[i] = true;
            current.push_back(nums[i]);
            helper(current, nums, i + 1);
            current.pop_back();
            used[i] = false;
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> current;
        used.resize(nums.size(), false);
        helper(current, nums, 0);
        return result;
    }
};