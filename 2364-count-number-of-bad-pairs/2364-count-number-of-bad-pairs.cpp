class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();
        long long totalPairs = (long long)n * (n - 1) / 2;
        long long goodPairs = 0;
        unordered_map<long long, long long> freq;
        for (int i = 0; i < nums.size(); i++) {
            long long key = nums[i] - i;
            goodPairs += freq[key];
            freq[key]++;
        }
        return totalPairs - goodPairs;
    }
};