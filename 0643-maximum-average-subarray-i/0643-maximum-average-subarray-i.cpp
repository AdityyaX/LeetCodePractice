class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = 0;
        int i = 0;
        int sum = 0;
        int maxVal = INT_MIN;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            if (j - i + 1 == k) {
                maxVal = max(maxVal, sum);
                ans = double(maxVal) / k;
                sum -= nums[i];
                i++;
            }
        }
        return ans;
    }
};