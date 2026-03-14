class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> hashset(nums.begin(), nums.end());
        return hashset.size() != nums.size();
    }
};