class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> seen;
        seen[0] = -1;
        int sum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            int rem = sum % k;
            if (seen.find(rem) != seen.end()) {
                if (i - seen[rem] >= 2)
                    return true;
            } else {
                seen[rem] = i;
            }
        }
        return false;
    }
};