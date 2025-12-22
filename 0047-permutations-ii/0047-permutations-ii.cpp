class Solution {
public:
    set<vector<int>> st;

    vector<bool> used;
    void helper(vector<int> nums, int i, vector<int>& current) {
        if (current.size() == nums.size()) {
            st.insert(current);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;
            used[i] = true;
            current.push_back(nums[i]);
            helper(nums, i + 1, current);
            current.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> current;
        used.resize(nums.size(), false);
        helper(nums, 0, current);
        vector<vector<int>> result(st.begin(), st.end());
        return result;
    }
};