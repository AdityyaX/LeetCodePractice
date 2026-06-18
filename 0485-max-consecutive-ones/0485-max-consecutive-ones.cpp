class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int start = 0;
        int maxlen = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 1) {
                start = i + 1;
            }
            maxlen = max(maxlen, i - start + 1);
        }
        return maxlen;
    }
};