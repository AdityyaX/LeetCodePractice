class Solution {
public:
    /*
    brute force approach can be run two loops and check if sum==target or not if
    yes return true else false in unordered map search th remaining value
    one approach can be unordered map which i can think of right now.
    both one pass and two pass
    */
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mpp;
        for (int i = 0; i < nums.size(); i++) {
            int remaining = target - nums[i];
            if (mpp.count(remaining)) {
                return {i, mpp[remaining]};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};