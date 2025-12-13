class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> sum(n);
        int count = 0;
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += nums[i];
            sum[i] = total;
        }
        for (int i = 0; i < n; i++) {
            if (sum[i] == k)
                count++;
            for (int j = i + 1; j < n; j++) {
                if (sum[j] - sum[i] == k)
                    count++;
            }
        }
        return count;
    }
};