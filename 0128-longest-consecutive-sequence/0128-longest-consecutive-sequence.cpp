class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int count = 1, maxvalue = 1;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] == nums[i + 1])
                continue;
            if (nums[i] + 1 == nums[i + 1]) {
                count++;
                maxvalue = max(maxvalue, count);
            } else {
                count = 1;
            }
        }
        return maxvalue;
    }
};