class Solution {
public:
    /*this is done by backtracking
    here thing i was missing is sorting the nums else duplicate removal will no
    work*/
    void helper(vector<int> nums, vector<int> current, set<vector<int>>& st,
                int i) {

        if (i == nums.size()) {
            st.insert(current);
            return;
        }
        current.push_back(nums[i]);
        helper(nums, current, st, i + 1);
        current.pop_back();
        helper(nums, current, st, i + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int i = 0;
        vector<int> current;
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        helper(nums, current, st, i);
        vector<vector<int>> result(st.begin(), st.end());

        return result;
    }
};