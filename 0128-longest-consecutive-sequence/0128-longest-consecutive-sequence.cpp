class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int longest = 0;
        if (nums.size() == 0)
            return 0;
        for (int it : st) {
            if (!st.count(it - 1)) {
                int current = it;
                int streak = 1;
                while (st.count(current + 1)) {
                    current++;
                    streak++;
                }
                longest = max(longest, streak);
            }
        }
        return longest;
    }
};