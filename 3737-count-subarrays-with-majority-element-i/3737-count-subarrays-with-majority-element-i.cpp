class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            int score = 0;
            for (int j = i; j < nums.size(); j++) {
                score += (nums[j] == target ? 1 : -1);
                if (score > 0)
                    ans++;
            }
        }
        return ans;
    }
};