class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i = 0;
        double sum = 0;
        double maxAvg = -1e9;
        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];
            if (j - i + 1 == k) {
                maxAvg = max(maxAvg, sum / k);
                sum -= nums[i];
                i++;
            }
        }
        return maxAvg;
    }
};